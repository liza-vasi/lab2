#include "csharp_classunit.h"

const std::vector<std::string> csharp_classunit::ACCESS_MODIFIERS = {
    "public",
    "protected",
    "private",
    "internal",
    "protected internal",
    "private protected",
    "file"
};

const std::vector<std::string> csharp_classunit::CLASS_MODIFIER_STRINGS = {
    "",
    "public",
    "internal",
    "abstract",
    "sealed",
    "static",
    "partial"
};

csharp_classunit::csharp_classunit(const std::string& name)
    : m_name(name)
{
    m_fields.resize(7);
}

void csharp_classunit::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if (flags < 7) {
        accessModifier = static_cast<int>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

void csharp_classunit::setModifier(const std::string& modifier)
{
    m_classModifier = modifier;
}

void csharp_classunit::addInterface(const std::string& interfaceName)
{
    m_interfaces.push_back(interfaceName);
}

void csharp_classunit::setClassModifier(ClassModifier modifier)
{
    m_classModifierFlags = modifier;
}

void csharp_classunit::addClassModifier(ClassModifier modifier)
{
    m_classModifierFlags = static_cast<ClassModifier>(m_classModifierFlags | modifier);
}

std::string csharp_classunit::generateClassModifiers() const
{
    std::string result;

    if (m_classModifierFlags & PUBLIC_CLASS) {
        result += "public ";
    }
    if (m_classModifierFlags & INTERNAL_CLASS) {
        result += "internal ";
    }
    if (m_classModifierFlags & ABSTRACT_CLASS) {
        result += "abstract ";
    }
    if (m_classModifierFlags & SEALED_CLASS) {
        result += "sealed ";
    }
    if (m_classModifierFlags & STATIC_CLASS) {
        result += "static ";
    }
    if (m_classModifierFlags & PARTIAL_CLASS) {
        result += "partial ";
    }

    return result;
}

std::string csharp_classunit::compile(unsigned int level) const
{
    std::string result;

    // Добавление using System для Console.WriteLine
    if (level == 0) {
        result = "using System;\n\n";
    }
    result += generateShift(level);

    result += generateClassModifiers();

    if (!m_classModifier.empty()) {
        result += m_classModifier + " ";
    }

    result += "class " + m_name;

    // Интерфейсы
    if (!m_interfaces.empty()) {
        result += " : ";
        for (size_t i = 0; i < m_interfaces.size(); ++i) {
            if (i > 0) result += ", ";
            result += m_interfaces[i];
        }
    }
    result += "\n" + generateShift(level) + "{\n";

    for (size_t i = 0; i < 7; ++i) {
        if (m_fields[i].empty()) continue;

        result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + "\n";
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += "\n";
    }

    result += generateShift(level) + "}\n";
    return result;
}

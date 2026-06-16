#include "csharp_classunit.h"

const std::vector<std::string> csharp_classunit::ACCESS_MODIFIERS = {"public", "protected", "private", "internal"};

csharp_classunit::csharp_classunit(const std::string& name)
    : m_name(name)
{
    m_fields.resize(4); // public, protected, private, internal
}

void csharp_classunit::add(const std::shared_ptr<Unit>& unit, Flags flags)// добавляем метод в класс
{
    int accessModifier = PRIVATE;
    if (flags < 4) {
        accessModifier = static_cast<int>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

std::string csharp_classunit::compile(unsigned int level) const
{
    std::string result;

    // Добавление using System для Console.WriteLine
    if (level == 0) {
        result = "using System;\n\n";
    }
    result += generateShift(level);

    // Модификатор класса (public, internal, abstract, sealed)
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

    // Секции с модификаторами доступа
    for (size_t i = 0; i < 4; ++i) {
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

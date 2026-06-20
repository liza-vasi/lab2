#include "csharp_classunit.h"

const std::vector<std::string> CSharpClassUnit::ACCESS_MODIFIERS = {
    "public",
    "protected",
    "private",
    "internal",
    "protected internal",
    "private protected",
    "file"
};

CSharpClassUnit::CSharpClassUnit(const std::string& name)
    : AbstractClassUnit(name)
{
    m_fields.resize(7);
}

void CSharpClassUnit::setClassModifier(const std::string& modifier) {
    m_classModifier = modifier;
}

void CSharpClassUnit::addInterface(const std::string& interfaceName) {
    m_interfaces.push_back(interfaceName);
}

void CSharpClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    int accessModifier = PRIVATE;
    if (flags < 7) {
        accessModifier = static_cast<int>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

std::string CSharpClassUnit::compile(unsigned int level) const {
    std::string result;

    if (level == 0) {
        result = "using System;\n\n";
    }
    result += generateShift(level);

    if (!m_classModifier.empty()) {
        result += m_classModifier + " ";
    }
    result += "class " + m_name;

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

        result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " ";
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += "\n";
    }

    result += generateShift(level) + "}\n";
    return result;
}

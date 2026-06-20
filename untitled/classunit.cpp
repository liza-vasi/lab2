#include "classunit.h"

const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = {"public:", "protected:", "private:"};

ClassUnit::ClassUnit(const std::string& name)
    : AbstractClassUnit(name)
{
    m_fields.resize(3);
}

void ClassUnit::setClassModifier(const std::string& modifier) {
    m_classModifier = modifier;
}

void ClassUnit::addInterface(const std::string& interfaceName) {
    m_interfaces.push_back(interfaceName);
}

void ClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    int accessModifier = PRIVATE;
    if (flags < 3) {
        accessModifier = static_cast<int>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

std::string ClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);

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
    result += " {\n";

    for (size_t i = 0; i < 3; ++i) {
        if (m_fields[i].empty()) continue;

        result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + "\n";
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";
    return result;
}

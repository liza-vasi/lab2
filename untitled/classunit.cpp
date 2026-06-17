#include "classunit.h"

const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = {"public:", "protected:", "private:"};

ClassUnit::ClassUnit(const std::string& name)
    :AbstractClassUnit(name)
{
    m_fields.resize(3);
}

void ClassUnit::add(const std::shared_ptr<AbstractUnit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if (flags < 3) {
        accessModifier = static_cast<int>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

std::string ClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + " {\n";

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

#include "java_classunit.h"

const std::vector<std::string> JavaClassUnit::ACCESS_MODIFIERS = {
    "public",
    "protected",
    "private",
    ""  // package-private — пустая строка
};

JavaClassUnit::JavaClassUnit(const std::string& name)
    : m_name(name)
{
    m_fields.resize(4);
}

void JavaClassUnit::setClassModifier(const std::string& modifier)
{
    m_classModifier = modifier;
}

void JavaClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if (flags < 4) {
        accessModifier = static_cast<int>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

std::string JavaClassUnit::compile(unsigned int level) const
{
    std::string result;

    result += generateShift(level);

    if (!m_classModifier.empty()) {
        result += m_classModifier + " ";
    }
    result += "class " + m_name;

    result += " {\n";

    for (size_t i = 0; i < 4; ++i) {
        if (m_fields[i].empty()) continue;

        // Для package-private не добавляем модификатор
        if (!ACCESS_MODIFIERS[i].empty()) {
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " ";
        } else {
            result += generateShift(level + 1);  // просто отступ
        }

        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += "\n";
    }

    result += generateShift(level) + "}\n";
    return result;
}

#include "csharp_classunit.h"

const std::vector<std::string> CSharpClassUnit::ACCESS_MODIFIERS = {
    "public",
    "protected",
    "private",
    "internal"
};

CSharpClassUnit::CSharpClassUnit(const std::string& name)
    : m_name(name)
{
    m_fields.resize(4);
}

void CSharpClassUnit::setClassModifier(const std::string& modifier)
{
    m_classModifier = modifier;
}

void CSharpClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if (flags < 4) {
        accessModifier = static_cast<int>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

std::string CSharpClassUnit::compile(unsigned int level) const
{
    std::string result;

    if (level == 0) {
        result = "using System;\n\n";
    }
    result += generateShift(level);

    if (!m_classModifier.empty()) {
        result += m_classModifier + " ";
    }
    result += "class " + m_name;

    result += "\n" + generateShift(level) + "{\n";

    for (size_t i = 0; i < 4; ++i) {
        if (m_fields[i].empty()) continue;

        // ✅ Убираем лишний перевод строки
        result += generateShift(level + 1) + ACCESS_MODIFIERS[i];
        // ✅ Добавляем пробел, а не перевод строки!
        result += " ";
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += "\n";
    }

    result += generateShift(level) + "}\n";
    return result;
}

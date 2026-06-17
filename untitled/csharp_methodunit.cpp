#include "csharp_methodunit.h"

CSharpMethodUnit::CSharpMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags)
{
}

void CSharpMethodUnit::add(const std::shared_ptr<Unit>& unit, Unit::Flags)
{
    m_body.push_back(unit);
}

std::string CSharpMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & PUBLIC) result += "public ";
    if (m_flags & PRIVATE) result += "private ";
    if (m_flags & PROTECTED) result += "protected ";
    if (m_flags & INTERNAL) result += "internal ";
    if (m_flags & PROTECTED_INTERNAL) result += "protected internal ";
    if (m_flags & PRIVATE_PROTECTED) result += "private protected ";


    if (m_flags & STATIC) result += "static ";
    if (m_flags & VIRTUAL) result += "virtual ";
    if (m_flags & ABSTRACT) result += "abstract ";
    if (m_flags & OVERRIDE) result += "override ";
    if (m_flags & SEALED) result += "sealed ";
    if (m_flags & NEW) result += "new ";
    result += m_returnType + " " + m_name + "()";

    if (m_flags & ABSTRACT) {
        result += ";\n";
        return result;
    }

    result += "\n" + generateShift(level) + "{\n";

    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

#include "java_methodunit.h"

JavaMethodUnit::JavaMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags)
    : AbstractMethodUnit(name, returnType, flags)
{
}

void JavaMethodUnit::add(const std::shared_ptr<Unit>& unit, Unit::Flags) {
    m_body.push_back(unit);
}

std::string JavaMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);

    if (m_flags & PUBLIC) result += "public ";
    if (m_flags & PRIVATE) result += "private ";
    if (m_flags & PROTECTED) result += "protected ";

    if (m_flags & STATIC) result += "static ";
    if (m_flags & FINAL) result += "final ";
    if (m_flags & ABSTRACT) result += "abstract ";
    if (m_flags & SYNCHRONIZED) result += "synchronized ";
    if (m_flags & NATIVE) result += "native ";

    result += m_returnType + " " + m_name + "()";

    if (m_flags & ABSTRACT || m_flags & NATIVE) {
        result += ";\n";
        return result;
    }

    result += " {\n";

    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

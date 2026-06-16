#include "csharp_methodunit.h"

csharp_methodunit::csharp_methodunit(const std::string& name, const std::string& returnType, Unit::Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags)
{
}

void csharp_methodunit::add(const std::shared_ptr<Unit>& unit, Unit::Flags)
{
    m_body.push_back(unit);
}

std::string csharp_methodunit::generateModifiers() const
{
    std::string result;

    // Модификаторы доступа
    if (m_flags & PUBLIC) {
        result += "public ";
    }
    if (m_flags & PRIVATE) {
        result += "private ";
    }
    if (m_flags & PROTECTED) {
        result += "protected ";
    }
    if (m_flags & INTERNAL) {
        result += "internal ";
    }

    // Модификаторы поведения
    if (m_flags & STATIC) {
        result += "static ";
    }
    if (m_flags & VIRTUAL) {
        result += "virtual ";
    }
    if (m_flags & ABSTRACT) {
        result += "abstract ";
    }
    if (m_flags & SEALED) {
        result += "sealed ";
    }
    if (m_flags & OVERRIDE) {
        result += "override ";
    }
    if (m_flags & NEW) {
        result += "new ";
    }

    return result;
}

std::string csharp_methodunit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    result += generateModifiers();
    result += m_returnType + " " + m_name + "()";

    if (m_flags & ABSTRACT) {
        result += ";\n";
        return result;
    }

    result += "\n" + generateShift(level) + "{\n";

    // генерируем все операторы внутри тела
    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

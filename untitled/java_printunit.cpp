#include "java_printunit.h"

JavaPrintUnit::JavaPrintUnit(const std::string& text)
    : m_text(text)
{
}

std::string JavaPrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
}

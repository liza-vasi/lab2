#include "csharp_printunit.h"

CSharpPrintUnit::CSharpPrintUnit(const std::string& text)
    : m_text(text)
{
}

std::string CSharpPrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
}

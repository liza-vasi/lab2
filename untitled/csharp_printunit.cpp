#include "csharp_printunit.h"

csharp_printunit::csharp_printunit(const std::string& text): m_text(text)
{
}

std::string csharp_printunit::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
}

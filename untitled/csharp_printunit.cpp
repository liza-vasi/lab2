#include "csharp_printunit.h"

CSharpPrintUnit::CSharpPrintUnit(const std::string& text)
    : PrintOperatorUnit(text)  // ← вызываем конструктор PrintOperatorUnit!
{
}

std::string CSharpPrintUnit::compile(unsigned int level) const
{
    // ✅ m_text теперь protected и доступен!
    return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
}

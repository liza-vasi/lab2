#include "printoperatorunit.h"


PrintOperatorUnit::PrintOperatorUnit(const std::string& text)
    : AbstractPrintUnit(text)
{
}

std::string PrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}

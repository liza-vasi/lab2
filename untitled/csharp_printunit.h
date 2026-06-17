#ifndef CSHARP_PRINTUNIT_H
#define CSHARP_PRINTUNIT_H

#include "unit.h"
#include <string>

class CSharpPrintUnit : public Unit
{
public:
    explicit CSharpPrintUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif

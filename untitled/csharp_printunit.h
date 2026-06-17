#ifndef CSHARP_PRINTUNIT_H
#define CSHARP_PRINTUNIT_H

#include "printoperatorunit.h"  // ← изменили!
#include <string>

class CSharpPrintUnit : public PrintOperatorUnit  // ← наследуемся от PrintOperatorUnit!
{
public:
    explicit CSharpPrintUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;
};

#endif

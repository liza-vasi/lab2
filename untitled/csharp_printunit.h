#ifndef CSHARP_PRINTUNIT_H
#define CSHARP_PRINTUNIT_H

#include "abstract_print_unit.h"
#include <string>

class CSharpPrintUnit : public AbstractPrintUnit {
public:
    explicit CSharpPrintUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const override;
};

#endif

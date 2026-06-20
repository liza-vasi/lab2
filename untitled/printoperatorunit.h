#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include "abstract_print_unit.h"
#include <string>

class PrintOperatorUnit : public AbstractPrintUnit {
public:
    explicit PrintOperatorUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const override;
};

#endif

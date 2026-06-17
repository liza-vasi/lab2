#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include <string>
#include "abstract_print_unit.h"

class PrintOperatorUnit : public AbstractPrintUnit
{
public:
    explicit PrintOperatorUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

protected:
    std::string m_text;
};

#endif // PRINTOPERATORUNIT_H

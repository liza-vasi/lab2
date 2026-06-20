#ifndef ABSTRACT_PRINT_UNIT_H
#define ABSTRACT_PRINT_UNIT_H

#include "unit.h"
#include <string>

class AbstractPrintUnit : public Unit {
public:
    explicit AbstractPrintUnit(const std::string& text) : m_text(text) {}

    virtual ~AbstractPrintUnit() = default;

    virtual std::string compile(unsigned int level = 0) const override = 0;

protected:
    std::string m_text;
};

#endif

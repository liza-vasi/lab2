#ifndef ABSTRACT_PRINT_UNIT_H
#define ABSTRACT_PRINT_UNIT_H

#include "abstractunit.h"
#include <string>

/*
 * Абстрактный оператор печати.
 * Наследники определяют свой синтаксис вывода.
 */
class AbstractPrintUnit : public AbstractUnit {
public:
    explicit AbstractPrintUnit(const std::string& text);
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    std::string m_text;
};

#endif

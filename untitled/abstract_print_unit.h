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
    explicit AbstractPrintUnit(const std::string& text) : m_text(text) {}

    virtual ~AbstractPrintUnit() = default;

    //Генерирует код оператора печати.

    virtual std::string compile(unsigned int level = 0) const override = 0;

protected:
    std::string m_text;  // текст для вывода
};

#endif

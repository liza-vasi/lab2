#ifndef ABSTRACT_METHOD_UNIT_H
#define ABSTRACT_METHOD_UNIT_H

#include "abstractunit.h"
#include <vector>
#include <string>

/* Абстрактный метод.
 * Не содержит модификаторов — наследники определяют свои.*/
class AbstractMethodUnit : public AbstractUnit {
public:
    AbstractMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
        : m_name(name), m_returnType(returnType), m_flags(flags) {}

    virtual ~AbstractMethodUnit() = default;

    // Добавляет оператор в тело метода.

    virtual void add(const std::shared_ptr<AbstractUnit>& unit, Flags flags = 0) override = 0;

    //Генерирует код метода.
    virtual std::string compile(unsigned int level = 0) const override = 0;

    /*
     * Проверяет корректность комбинации модификаторов.
     * Каждый язык реализует свою логику проверки.
     */
    virtual bool validateModifiers(Flags flags) const = 0;

protected:
    std::string m_name;          // имя метода
    std::string m_returnType;    // тип возвращаемого значения
    Flags m_flags;               // битовая маска модификаторов
    std::vector<std::shared_ptr<AbstractUnit>> m_body;  // тело метода
};

#endif

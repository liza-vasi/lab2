#ifndef ABSTRACT_CLASS_UNIT_H
#define ABSTRACT_CLASS_UNIT_H

#include "abstractunit.h"
#include <vector>
#include <string>

/*Абстрактный класс для представления класса
 * Не содержит модификаторов — наследники определяют свои*/
class AbstractClassUnit : public AbstractUnit {
public:
    explicit AbstractClassUnit(const std::string& name) : m_name(name) {}

    virtual ~AbstractClassUnit() = default;

    /* Добавляет метод в класс.
     * flags интерпретируются наследниками по-своему.*/
    virtual void add(const std::shared_ptr<AbstractUnit>& unit, Flags flags) override = 0;


     // Генерирует код класса.

    virtual std::string compile(unsigned int level = 0) const override = 0;

    /*Устанавливает модификатор класса (например "public", "abstract").
     * Каждый язык определяет свои допустимые значения.
     */
    virtual void setClassModifier(const std::string& modifier) = 0;


     //Добавляет интерфейс, который реализует класс.

    virtual void addInterface(const std::string& interfaceName) = 0;

protected:
    std::string m_name;                            // имя класса
    using Fields = std::vector<std::shared_ptr<AbstractUnit>>;
    std::vector<Fields> m_fields;                  // методы по секциям доступа
};

#endif

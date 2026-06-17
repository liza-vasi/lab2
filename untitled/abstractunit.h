#ifndef ABSTRACT_UNIT_H
#define ABSTRACT_UNIT_H

#include <string>
#include <memory>
#include <vector>
#include <stdexcept>


 /* Базовый абстрактный класс для всех элементов кода.
 * Определяет общий интерфейс, но ничего не знает о конкретных языках.*/
class AbstractUnit {
public:
    using Flags = unsigned int;

    virtual ~AbstractUnit() = default;

    /* Добавляет вложенный элемент.
     * По умолчанию операция не поддерживается.*/
    virtual void add(const std::shared_ptr<AbstractUnit>&, Flags) {
        throw std::runtime_error("Not supported");
    }


     /* Генерирует код. Обязателен для переопределения.*/
    virtual std::string compile(unsigned int level = 0) const = 0;

protected:

     /* Создаёт отступы для форматирования кода.*/
    virtual std::string generateShift(unsigned int level) const {
        static const auto DEFAULT_SHIFT = "    ";
        std::string result;
        for (unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif

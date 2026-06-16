#ifndef CSHARP_METHODUNIT_H
#define CSHARP_METHODUNIT_H

#include "unit.h"
#include <vector>
#include <string>

// Класс для генерации C# метода

class csharp_methodunit : public Unit
{
public:
    // Модификаторы метода C#
    enum Modifier {
        // Модификаторы доступа
        PUBLIC      = 1 << 0,
        PRIVATE     = 1 << 1,
        PROTECTED   = 1 << 2,
        INTERNAL    = 1 << 3,

        // Модификаторы поведения
        STATIC      = 1 << 4,
        VIRTUAL     = 1 << 5,
        ABSTRACT    = 1 << 6,
        SEALED      = 1 << 7,
        OVERRIDE    = 1 << 8,
        NEW         = 1 << 9,
    };

    csharp_methodunit(const std::string& name, const std::string& returnType, Unit::Flags flags);

    void add(const std::shared_ptr<Unit>& unit, Unit::Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Unit::Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;

    // Вспомогательный метод для генерации модификаторов
    std::string generateModifiers() const;
};

#endif // CSHARP_METHODUNIT_H

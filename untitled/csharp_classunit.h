#ifndef CSHARP_CLASSUNIT_H
#define CSHARP_CLASSUNIT_H

#include "unit.h"
#include <vector>
#include <string>

class csharp_classunit : public Unit
{
public:

    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE
    };

    enum ClassModifier {
        NONE = 0,
        PUBLIC_CLASS = 1 << 0,
        INTERNAL_CLASS = 1 << 1,
        ABSTRACT_CLASS = 1 << 2,
        SEALED_CLASS = 1 << 3,
        STATIC_CLASS = 1 << 4,
        PARTIAL_CLASS = 1 << 5,
    };

    explicit csharp_classunit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

    // Методы для настройки класса
    void setModifier(const std::string& modifier);
    void addInterface(const std::string& interfaceName);

    void setClassModifier(ClassModifier modifier);
    void addClassModifier(ClassModifier modifier);

private:
    std::string m_name;
    std::string m_classModifier;
    ClassModifier m_classModifierFlags = NONE;
    std::vector<std::string> m_interfaces;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;

    static const std::vector<std::string> ACCESS_MODIFIERS;
    static const std::vector<std::string> CLASS_MODIFIER_STRINGS;

    // Вспомогательный метод для генерации модификаторов класса
    std::string generateClassModifiers() const;
};

#endif // CSHARP_CLASSUNIT_H

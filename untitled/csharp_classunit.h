#ifndef CSHARP_CLASSUNIT_H
#define CSHARP_CLASSUNIT_H

#include "unit.h"
#include <vector>
#include <string>
class csharp_classunit: public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL
    };
    explicit csharp_classunit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
    // C# специфичные методы
    void setModifier(const std::string& modifier) {
        m_classModifier = modifier;
    }
    void addInterface(const std::string& interfaceName) {
        m_interfaces.push_back(interfaceName);
    }

private:
    std::string m_name;
    std::string m_classModifier;
    std::vector<std::string> m_interfaces;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;

    static const std::vector<std::string> ACCESS_MODIFIERS;
};

#endif // CSHARP_CLASSUNIT_H

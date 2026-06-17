#ifndef CSHARP_CLASSUNIT_H
#define CSHARP_CLASSUNIT_H

#include "unit.h"  // ← НЕ classunit.h!
#include <vector>
#include <string>

class CSharpClassUnit : public Unit  // ← наследуемся от Unit!
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL
    };

    explicit CSharpClassUnit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

    void setClassModifier(const std::string& modifier);

private:
    std::string m_name;
    std::string m_classModifier;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;

    static const std::vector<std::string> ACCESS_MODIFIERS;
};

#endif

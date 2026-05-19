#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <string>
#include <vector>
#include <memory>
#include "unit.h"

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit ClassUnit(const std::string& name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags)override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // CLASSUNIT_H

#ifndef CSHARP_METHODUNIT_H
#define CSHARP_METHODUNIT_H

#include "unit.h"
#include <vector>
#include <string>

class CSharpMethodUnit : public Unit
{
public:
    enum Modifier {
        PUBLIC = 1 << 0,
        PRIVATE = 1 << 1,
        PROTECTED = 1 << 2,
        INTERNAL = 1 << 3,
        PROTECTED_INTERNAL = 1 << 4,
        PRIVATE_PROTECTED = 1 << 5,

        STATIC = 1 << 6,
        VIRTUAL = 1 << 7,
        ABSTRACT = 1 << 8,
        OVERRIDE = 1 << 9,
        SEALED = 1 << 10,
        NEW = 1 << 11
    };

    CSharpMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags);

    void add(const std::shared_ptr<Unit>& unit, Unit::Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Unit::Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif

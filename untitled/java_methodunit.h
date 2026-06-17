#ifndef JAVA_METHODUNIT_H
#define JAVA_METHODUNIT_H

#include "unit.h"
#include <vector>
#include <string>

class JavaMethodUnit : public Unit
{
public:
    enum Modifier {
        PUBLIC = 1 << 0,
        PRIVATE = 1 << 1,
        PROTECTED = 1 << 2,
        STATIC = 1 << 3,
        FINAL = 1 << 4,
        ABSTRACT = 1 << 5,
        SYNCHRONIZED = 1 << 6,
        NATIVE = 1 << 7
    };

    JavaMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags);

    void add(const std::shared_ptr<Unit>& unit, Unit::Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Unit::Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif

#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <string>
#include <vector>
#include <memory>
#include "unit.h"

class MethodUnit : public Unit
{
public:
    enum Modifier {
        STATIC  = 1,
        CONST   = 1 << 1,
        VIRTUAL = 1 << 2
    };

    MethodUnit(const std::string& name, const std::string& returnType, Flags flags);

    void add(const std::shared_ptr<Unit>& unit, Flags = 0) override;

    std::string compile(unsigned int level = 0) const override;

protected:  // ← ИЗМЕНИЛИ С private НА protected!
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif

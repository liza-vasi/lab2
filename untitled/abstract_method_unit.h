#ifndef ABSTRACT_METHOD_UNIT_H
#define ABSTRACT_METHOD_UNIT_H

#include "unit.h"
#include <vector>
#include <string>

class AbstractMethodUnit : public Unit {
public:
    AbstractMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
        : m_name(name), m_returnType(returnType), m_flags(flags) {}

    virtual ~AbstractMethodUnit() = default;

    virtual void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) override = 0;
    virtual std::string compile(unsigned int level = 0) const override = 0;

protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif

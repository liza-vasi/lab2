#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "abstract_method_unit.h"
#include <vector>
#include <string>

class MethodUnit : public AbstractMethodUnit
{
public:
    enum Modifier {
        STATIC  = 1,
        CONST   = 1 << 1,
        VIRTUAL = 1 << 2
    };

    MethodUnit(const std::string& name, const std::string& returnType, Flags flags);

    void add(const std::shared_ptr<AbstractUnit>& unit, Flags = 0) override;
    std::string compile(unsigned int level = 0) const override;


private:

};

#endif

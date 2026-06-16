#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H


#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;
    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& returnType, const std::string& name,Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0;
};

#endif // ABSTRACTFACTORY_H

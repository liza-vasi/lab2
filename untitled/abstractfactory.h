#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <string>
#include <memory>
#include "unit.h"

class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;

    virtual std::shared_ptr<Unit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<Unit> createPrintUnit(const std::string& text) = 0;
};

#endif

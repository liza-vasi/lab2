#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <string>
#include <memory>
#include "abstract_class_unit.h"
#include "abstract_method_unit.h"
#include "abstract_print_unit.h"

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;

    virtual std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<AbstractMethodUnit> createMethodUnit(
        const std::string& name,
        const std::string& returnType,
        Unit::Flags flags
        ) = 0;
    virtual std::shared_ptr<AbstractPrintUnit> createPrintUnit(const std::string& text) = 0;
};

#endif

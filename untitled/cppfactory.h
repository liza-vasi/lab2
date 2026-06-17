#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "abstractfactory.h"
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

class CppFactory : public AbstractFactory
{
public:
    std::shared_ptr<Unit> createClassUnit(const std::string& name) override {
        return std::make_shared<ClassUnit>(name);
    }

    std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<MethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<Unit> createPrintUnit(const std::string& text) override {
        return std::make_shared<PrintOperatorUnit>(text);
    }
};

#endif

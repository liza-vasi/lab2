#ifndef JAVA_FACTORY_H
#define JAVA_FACTORY_H

#include "abstractfactory.h"
#include "java_classunit.h"
#include "java_methodunit.h"
#include "java_printunit.h"

class JavaFactory : public AbstractFactory
{
public:
    std::shared_ptr<Unit> createClassUnit(const std::string& name) override {
        auto unit = std::make_shared<JavaClassUnit>(name);
        unit->setClassModifier("public");
        return unit;
    }

    std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<Unit> createPrintUnit(const std::string& text) override {
        return std::make_shared<JavaPrintUnit>(text);
    }
};

#endif

#ifndef CSHARP_FACTORY_H
#define CSHARP_FACTORY_H

#include "abstractfactory.h"
#include "csharp_classunit.h"
#include "csharp_methodunit.h"
#include "csharp_printunit.h"
#include <memory>
#include <string>

class csarp_factory : public AbstractFactory
{
public:
    csarp_factory() = default;
    ~csarp_factory() override = default;

    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<csharp_classunit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(
        const std::string& returnType,
        const std::string& name,
        Unit::Flags flags
        ) override {
        return std::make_shared<csharp_methodunit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<csharp_printunit>(text);
    }
};

#endif // CSHARP_FACTORY_H

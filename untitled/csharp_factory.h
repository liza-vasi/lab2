#ifndef CSHARP_FACTORY_H
#define CSHARP_FACTORY_H

#include "abstractfactory.h"
#include "csharp_classunit.h"
#include "csharp_methodunit.h"
#include "csharp_printunit.h"   // ← ЭТОТ ФАЙЛ ДОЛЖЕН БЫТЬ ПОДКЛЮЧЁН!

class CSharpFactory : public AbstractFactory
{
public:
    std::shared_ptr<Unit> createClassUnit(const std::string& name) override {
        auto unit = std::make_shared<CSharpClassUnit>(name);
        unit->setClassModifier("public");
        return unit;
    }

    std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<Unit> createPrintUnit(const std::string& text) override {
        return std::make_shared<CSharpPrintUnit>(text);   // ← теперь должно работать!
    }
};

#endif

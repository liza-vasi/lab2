#ifndef CPPFACTORY_H
#define CPPFACTORY_H


#include "abstractfactory.h"

class CppFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<ClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& returnType,const std::string& name,Unit::Flags flags)
         override {return std::make_shared<MethodUnit>(name, returnType, flags);}

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<PrintOperatorUnit>(text);

    }
};
#endif // CPPFACTORY_H

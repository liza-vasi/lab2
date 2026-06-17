#include <QCoreApplication>
#include <iostream>
#include <memory>

#include "abstractfactory.h"
#include "cppfactory.h"
#include "csharp_factory.h"

std::string generateProgram(AbstractFactory& factory) {
    auto myClass = factory.createClassUnit("MyClass");
    auto method = factory.createMethodUnit("testFunc", "void", 0);
    // ✅ Убираем \n!
    auto print = factory.createPrintUnit("Hello, world!");
    method->add(print, 0);
    myClass->add(method, 0);
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "========== C++ ==========" << std::endl;
    CppFactory cppFactory;
    std::cout << generateProgram(cppFactory) << std::endl;

    std::cout << "\n========== C# ==========" << std::endl;
    CSharpFactory csharpFactory;
    std::cout << generateProgram(csharpFactory) << std::endl;

    return a.exec();
}

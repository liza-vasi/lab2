#include <iostream>
#include <memory>

#include "abstractfactory.h"
#include "cppfactory.h"
#include "csharp_factory.h"
#include "java_factory.h"

std::string generateProgram(AbstractFactory& factory) {
    auto myClass = factory.createClassUnit("MyClass");
    auto method = factory.createMethodUnit("test", "void", 0);
    auto print = factory.createPrintUnit("Hello, World!");

    method->add(print, 0);
    myClass->add(method, 0);

    return myClass->compile();
}

int main() {
    CppFactory cppFactory;
    std::cout << "C++" << std::endl;
    std::cout << generateProgram(cppFactory) << std::endl;

    CSharpFactory csharpFactory;
    std::cout << "C#" << std::endl;
    std::cout << generateProgram(csharpFactory) << std::endl;

    JavaFactory javaFactory;
    std::cout << "JAVA" << std::endl;
    std::cout << generateProgram(javaFactory) << std::endl;

    return 0;
}

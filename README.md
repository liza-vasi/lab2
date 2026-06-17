# Отчёт по лабораторной работе №2

### Постановка задачи
Разработать расширяемую систему для генерации кода на разных языках программирования (C++, C#, Java), используя паттерн "Абстрактная фабрика".

### Исходные данные
Имеется реализация генератора кода на C++, включающая классы:
- **Unit** — базовый абстрактный класс
- **ClassUnit** — генерация классов
- **MethodUnit** — генерация методов
- **PrintOperatorUnit** — генерация операторов печати

**Недостаток:** функция `generateProgram()` привязана к формированию кода на C++.

## Решение

### Общая архитектура
В основе решения  лежит архитектура генерации кода, построенная с использованием паттернов и принципов проектирования, что обеспечивает расширяемость системы и поддержку различных языков.

#### Принципы проектирования
- **Open/Closed** — базовые классы открыты для расширения, но закрыты для модификации. Существующий код не меняется при добавлении нового языка.
- Код зависит от абстракций, а не от конкретных реализаций. Это позволяет легко заменять одну реализацию другой без изменения клиентского кода.

#### Паттерны проектирования
**Абстрактная фабрика** — паттерн используется для создания семейств взаимосвязанных объектов (класс, метод, оператор печати) для каждого языка программирования.

###  Паттерн "Абстрактная фабрика"
Паттерн используется когда:
- Система должна оставаться независимой от процесса создания новых объектов и от типов порождаемых объектов
- Необходимо создавать группы или семейства взаимосвязанных объектов, исключая возможность одновременного использования объектов из разных семейств

Введены следующие абстрактные сущности (интерфейсы):
- Базовый класс Unit.
Абстрактный базовый класс для всех синтаксических единиц кода. Содержит чисто виртуальный метод `compile()` и вспомогательную функцию `generateShift()` для создания отступов.
- Абстрактная фабрика AbstractFactory.
Интерфейс, объявляющий методы для создания семейств связанных объектов.

|Язык|Класс	|Метод	|Оператор печати	|Фабрика|
|---|---|---|---|---|
|C++	|ClassUnit	|MethodUnit	|PrintOperatorUnit	|CppFactory|
|C#	|CSharpClassUnit	|CSharpMethodUnit	|CSharpPrintUnit	|CSharpFactory|
|Java	|JavaClassUnit	|JavaMethodUnit	|JavaPrintUnit	|JavaFactory|

Все языковые классы наследуются напрямую от Unit, что обеспечивает независимость реализаций и отсутствие конфликтов.


UML: https://drive.google.com/file/d/1KcCk1fe5QfR2mv8qyn6sTRrBSvv_6-Fn/view?usp=sharing

## Тестирование

- Генерация для C++
```cpp
#include "abstractfactory.h"
#include "cppfactory.h"

int main() {
    CppFactory factory;

    // Создаём класс с именем MyClass
    auto myClass = factory.createClassUnit("MyClass");

    // Создаём методы с разными модификаторами
    auto method1 = factory.createMethodUnit("test1", "void", 0);
    auto method2 = factory.createMethodUnit("test2", "void", MethodUnit::STATIC);

    // Создаём метод с оператором печати
    auto methodPrint = factory.createMethodUnit("testPrint", "void", 0);
    auto print = factory.createPrintUnit("Hello, World!");
    methodPrint->add(print, 0);

    // Добавляем методы в класс с разными модификаторами доступа
    myClass->add(method1, ClassUnit::PUBLIC);
    myClass->add(method2, ClassUnit::PRIVATE);
    myClass->add(method3, ClassUnit::PUBLIC);
    myClass->add(methodPrint, ClassUnit::PROTECTED);

    // Генерируем и выводим код
    std::cout << myClass->compile();

    return 0;
}
```
**Результат выполнения:**

```cpp
class MyClass {
public:
    void test1() {
    }
protected:
    void testPrint() {
        printf("Hello, World!");
    }
private:
    static void test2() {
    }
};
```
- Генерация для C#
```cpp
#include <iostream>
#include <memory>
#include "abstractfactory.h"
#include "csharp_factory.h"

int main() {
    auto factory = std::make_shared<CSharpFactory>();

    auto myClass = factory->createClassUnit("MyClass");

    auto method1 = factory->createMethodUnit("test1", "void", 0);
    auto method2 = factory->createMethodUnit("test2", "void", CSharpMethodUnit::STATIC);
    auto method3 = factory->createMethodUnit("test3", "void", CSharpMethodUnit::VIRTUAL);

    auto methodPrint = factory->createMethodUnit("testPrint", "void", 0);
    auto print = factory->createPrintUnit("Hello, World!");
    methodPrint->add(print, 0);

    myClass->add(method1, CSharpClassUnit::PUBLIC);
    myClass->add(method2, CSharpClassUnit::PRIVATE);
    myClass->add(method3, CSharpClassUnit::PUBLIC);
    myClass->add(methodPrint, CSharpClassUnit::PROTECTED);

    std::cout << myClass->compile();

    return 0;
}
```
**Результат выполнения:**
```cpp
using System;

public class MyClass {
    public void test1() {
    }
    public virtual void test3() {
    }
    protected void testPrint() {
        Console.WriteLine("Hello, World!");
    }
    private static void test2() {
    }
}
```
- Генерация для Java
```cpp
#include <iostream>
#include <memory>
#include "abstractfactory.h"
#include "java_factory.h"

int main() {
    auto factory = std::make_shared<JavaFactory>();

    auto myClass = factory->createClassUnit("MyClass");

    auto method1 = factory->createMethodUnit("test1", "void", 0);
    auto method2 = factory->createMethodUnit("test2", "void", JavaMethodUnit::STATIC);
    auto method3 = factory->createMethodUnit("test3", "void", JavaMethodUnit::FINAL);

    auto methodPrint = factory->createMethodUnit("testPrint", "void", 0);
    auto print = factory->createPrintUnit("Hello, World!");
    methodPrint->add(print, 0);

    myClass->add(method1, JavaClassUnit::PUBLIC);
    myClass->add(method2, JavaClassUnit::PRIVATE);
    myClass->add(method3, JavaClassUnit::PUBLIC);
    myClass->add(methodPrint, JavaClassUnit::PROTECTED);

    std::cout << myClass->compile();

    return 0;
}
```
**Результат выполнения:**
```cpp
public class MyClass {
    public void test1() {
    }
    public final void test3() {
    }
    protected void testPrint() {
        System.out.println("Hello, World!");
    }
    private static void test2() {
    }
}
```

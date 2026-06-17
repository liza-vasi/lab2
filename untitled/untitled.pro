QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        classunit.cpp \
        csharp_classunit.cpp \
        csharp_methodunit.cpp \
        csharp_printunit.cpp \
        java_classunit.cpp \
        java_methodunit.cpp \
        java_printunit.cpp \
        main.cpp \
        methodunit.cpp \
        printoperatorunit.cpp \
        unit.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstract_class_unit.h \
    abstract_method_unit.h \
    abstract_print_unit.h \
    abstractfactory.h \
    classunit.h \
    cppfactory.h \
    csharp_classunit.h \
    csharp_factory.h \
    csharp_methodunit.h \
    csharp_printunit.h \
    java_classunit.h \
    java_factory.h \
    java_methodunit.h \
    java_printunit.h \
    methodunit.h \
    printoperatorunit.h \
    unit.h

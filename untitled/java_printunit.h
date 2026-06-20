#ifndef JAVA_PRINTUNIT_H
#define JAVA_PRINTUNIT_H

#include "abstract_print_unit.h"
#include <string>

class JavaPrintUnit : public AbstractPrintUnit {
public:
    explicit JavaPrintUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const override;
};

#endif

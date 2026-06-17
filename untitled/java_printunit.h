#ifndef JAVA_PRINTUNIT_H
#define JAVA_PRINTUNIT_H

#include "unit.h"
#include <string>

class JavaPrintUnit : public Unit
{
public:
    explicit JavaPrintUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif

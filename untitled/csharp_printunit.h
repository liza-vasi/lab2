#ifndef CSHARP_PRINTUNIT_H
#define CSHARP_PRINTUNIT_H

#include "printoperatorunit.h"
#include <string>

class csharp_printunit : public  PrintOperatorUnit
{
public:
    explicit csharp_printunit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif

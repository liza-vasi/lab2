#ifndef JAVA_CLASSUNIT_H
#define JAVA_CLASSUNIT_H

#include "unit.h"
#include <vector>
#include <string>

class JavaClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PACKAGE_PRIVATE
    };

    explicit JavaClassUnit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
    void setClassModifier(const std::string& modifier);

private:
    std::string m_name;
    std::string m_classModifier;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;

    static const std::vector<std::string> ACCESS_MODIFIERS;
};

#endif

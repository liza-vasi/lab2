#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "abstract_class_unit.h"
#include <vector>
#include <string>

class ClassUnit : public AbstractClassUnit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    explicit ClassUnit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
    void setClassModifier(const std::string& modifier) override;
    void addInterface(const std::string& interfaceName) override;

private:
    std::string m_classModifier;
    std::vector<std::string> m_interfaces;
    static const std::vector<std::string> ACCESS_MODIFIERS;
};

#endif

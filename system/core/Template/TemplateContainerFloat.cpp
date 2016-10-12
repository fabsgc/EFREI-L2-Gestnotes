/*\
 | ------------------------------------------------------
 | @file : TemplateContainerFloat.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Flottant
 | ------------------------------------------------------
\*/

#include "TemplateContainerFloat.hpp"

    namespace core
    {
        TemplateContainerFloat::TemplateContainerFloat(std::string name, float value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerFloat::render() const
        {
            return "$" + mName + " = " + var2Str(mValue) + ";\n";
        }

        stringVector TemplateContainerFloat::renderChild() const
        {
            stringVector data;
            std::string result = "['" + mName + "'] = " + var2Str(mValue) + ";\n";
            data.push_back(result);

            return data;
        }

        TemplateContainerFloat::~TemplateContainerFloat()
        {

        }
    }

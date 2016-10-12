/*\
 | ------------------------------------------------------
 | @file : TemplateContainerString.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : String
 | ------------------------------------------------------
\*/

#include "TemplateContainerString.hpp"

    namespace core
    {
        TemplateContainerString::TemplateContainerString(std::string name, const std::string & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerString::render() const
        {
            return "$" + mName + " = '" + escape(mValue) + "';\n";
        }

        stringVector TemplateContainerString::renderChild() const
        {
            stringVector data;
            std::string result = "['" + mName + "'] = '" + escape(mValue) + "';\n";
            data.push_back(result);

            return data;
        }

        TemplateContainerString::~TemplateContainerString()
        {

        }
    }

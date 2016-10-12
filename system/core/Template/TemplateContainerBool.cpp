/*\
 | ------------------------------------------------------
 | @file : TemplateContainerBool.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : variable booléennes
 | ------------------------------------------------------
\*/

#include "TemplateContainerBool.hpp"

    namespace core
    {
        TemplateContainerBool::TemplateContainerBool(std::string name, bool value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerBool::render() const
        {
            if(mValue == true)
                return "$" + mName + " = true;\n";
            else
                return "$" + mName + " = false;\n";
        }

        stringVector TemplateContainerBool::renderChild() const
        {
            stringVector data;
            std::string result;

            if(mValue == true)
                result = "['" + mName + "'] = true;\n";
            else
                result = "['" + mName + "'] = false;\n";

            data.push_back(result);

            return data;
        }

        TemplateContainerBool::~TemplateContainerBool()
        {

        }
    }

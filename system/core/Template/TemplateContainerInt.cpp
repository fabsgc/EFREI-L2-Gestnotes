/*\
 | ------------------------------------------------------
 | @file : TemplateContainerInt.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Int
 | ------------------------------------------------------
\*/

#include "TemplateContainerInt.hpp"

    namespace core
    {
        TemplateContainerInt::TemplateContainerInt(std::string name, int value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerInt::render() const
        {
            return "$" + mName + " = " + var2Str(mValue) + ";\n";
        }

        stringVector TemplateContainerInt::renderChild() const
        {
            stringVector data;
            std::string result = "['" + mName + "'] = " + var2Str(mValue) + ";\n";
            data.push_back(result);

            return data;
        }

        TemplateContainerInt::~TemplateContainerInt()
        {

        }
    }

/*\
 | ------------------------------------------------------
 | @file : TemplateContainerDataVector.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : DataVector
 | ------------------------------------------------------
\*/

#include "TemplateContainerDataVector.hpp"

    namespace core
    {
        TemplateContainerDataVector::TemplateContainerDataVector(std::string name, const dataVector & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerDataVector::render() const
        {
            std::string content = "$" + mName + " = array();\n";

            for(auto i = mValue.begin(); i != mValue.end(); i++)
            {
                int k = 0;

                for(auto j = i->second.begin(); j != i->second.end(); j++)
                {
                    content += "$" + mName + "['" + i->first + "']['" + var2Str(k) + "'] = '" + escape(*j) + "';\n";
                    k++;
                }
            }

            return content;
        }

        stringVector TemplateContainerDataVector::renderChild() const
        {
            stringVector data;

            std::string content = "['" + mName + "'] = array();\n";
            data.push_back(content);

            for(auto i = mValue.begin(); i != mValue.end(); i++)
            {
                int k = 0;

                for(auto j = i->second.begin(); j != i->second.end(); j++)
                {
                    content = "['" + mName + "']['" + i->first + "']['" + var2Str(k) + "'] = '" + escape(*j) + "';\n";
                    data.push_back(content);
                }
            }

            return data;
        }

        TemplateContainerDataVector::~TemplateContainerDataVector()
        {

        }
    }

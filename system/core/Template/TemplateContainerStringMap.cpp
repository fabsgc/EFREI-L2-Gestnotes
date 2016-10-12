/*\
 | ------------------------------------------------------
 | @file : TemplateContainerStringMap.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : StringMap représente une ligne de DataMap
 | ------------------------------------------------------
\*/

#include "TemplateContainerStringMap.hpp"

    namespace core
    {
        TemplateContainerStringMap::TemplateContainerStringMap(std::string name, const stringMap & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerStringMap::render() const
        {
            std::string content = "$" + mName + " = array();\n";

            for(auto i = mValue.begin(); i != mValue.end(); i++)
            {
                content += "$" + mName + "['" + i->first + "'] = '" + escape(i->second) + "';\n";
            }

            return content;
        }

        stringVector TemplateContainerStringMap::renderChild() const
        {
            stringVector data;

            std::string content = "['" + mName + "'] = array();\n";
            data.push_back(content);

            for(auto i = mValue.begin(); i != mValue.end(); i++)
            {
                content = "['" + mName + "']['" + i->first + "'] = '" + escape(i->second) + "';\n";
                data.push_back(content);
            }

            return data;
        }

        TemplateContainerStringMap::~TemplateContainerStringMap()
        {

        }
    }

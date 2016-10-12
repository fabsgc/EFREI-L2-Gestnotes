/*\
 | ------------------------------------------------------
 | @file : TemplateContainerDataMap.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : DataMap est une structure contenant les données provenant d'une base de données
 | ------------------------------------------------------
\*/

#include "TemplateContainerDataMap.hpp"

    namespace core
    {
        TemplateContainerDataMap::TemplateContainerDataMap(std::string name, const dataMap & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerDataMap::render() const
        {
            std::string content = "$" + mName + " = array();\n";

            for(auto i = mValue.begin(); i != mValue.end(); i++)
            {
                for(auto j = i->second.begin(); j != i->second.end(); j++)
                {
                    content += "$" + mName + "['" + i->first + "']['" + j->first + "'] = '" + escape(j->second) + "';\n";
                }
            }

            return content;
        }

        stringVector TemplateContainerDataMap::renderChild() const
        {
            stringVector data;

            std::string content = "['" + mName + "'] = array();\n";
            data.push_back(content);

            for(auto i = mValue.begin(); i != mValue.end(); i++)
            {
                for(auto j = i->second.begin(); j != i->second.end(); j++)
                {
                    content = "['" + mName + "']['" + i->first + "']['" + j->first + "'] = '" + escape(j->second) + "';\n";
                    data.push_back(content);
                }
            }

            return data;
        }

        TemplateContainerDataMap::~TemplateContainerDataMap()
        {

        }
    }

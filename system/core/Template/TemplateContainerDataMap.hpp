/*\
 | ------------------------------------------------------
 | @file : TemplateContainerDataMap.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : DataMap est une structure contenant les données provenant d'une base de données
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERDATAMAP_HPP_INCLUDED
#define TEMPLATECONTAINERDATAMAP_HPP_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include "../../../function.hpp"
#include "TemplateContainer.hpp"

    namespace core
    {
        class TemplateContainerDataMap : public TemplateContainer
        {
            public :
                             TemplateContainerDataMap(std::string name, const dataMap& value);
                             ~TemplateContainerDataMap();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string mName;
                dataMap    mValue;
        };
    }

#endif // TEMPLATECONTAINERDATAMAP_HPP_INCLUDED

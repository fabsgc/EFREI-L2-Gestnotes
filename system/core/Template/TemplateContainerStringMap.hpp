/*\
 | ------------------------------------------------------
 | @file : TemplateContainerStringMap.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : StringMap représente une ligne de DataMap
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERSTRINGMAP_HPP_INCLUDED
#define TEMPLATECONTAINERSTRINGMAP_HPP_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include "../../../function.hpp"
#include "TemplateContainer.hpp"

    namespace core
    {
        class TemplateContainerStringMap : public TemplateContainer
        {
            public :
                             TemplateContainerStringMap(std::string name, const stringMap& value);
                             ~TemplateContainerStringMap();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string mName;
                stringMap mValue;
        };
    }

#endif // TEMPLATECONTAINERSTRINGMAP_HPP_INCLUDED

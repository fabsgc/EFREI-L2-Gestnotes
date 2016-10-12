/*\
 | ------------------------------------------------------
 | @file : TemplateContainerBool.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : variable booléennes
 | ------------------------------------------------------
\*/


#ifndef TEMPLATECONTAINERBOOL_HPP_INCLUDED
#define TEMPLATECONTAINERBOOL_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../function.hpp"
#include "TemplateContainer.hpp"

    namespace core
    {
        class TemplateContainerBool : public TemplateContainer
        {
            public :
                             TemplateContainerBool(std::string name, bool value);
                             ~TemplateContainerBool();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string mName;
                bool        mValue;
        };
    }

#endif // TEMPLATECONTAINERBOOL_HPP_INCLUDED

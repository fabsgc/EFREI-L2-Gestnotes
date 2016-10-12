/*\
 | ------------------------------------------------------
 | @file : TemplateContainerString.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : String
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERSTRING_HPP_INCLUDED
#define TEMPLATECONTAINERSTRING_HPP_INCLUDED

#include <iostream>
#include <string>
#include <regex>
#include "../../../function.hpp"
#include "TemplateContainer.hpp"

    namespace core
    {
        class TemplateContainerString : public TemplateContainer
        {
            public :
                             TemplateContainerString(std::string name, const std::string& value);
                             ~TemplateContainerString();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string mName;
                std::string mValue;
        };
    }

#endif // TEMPLATECONTAINERSTRING_HPP_INCLUDED

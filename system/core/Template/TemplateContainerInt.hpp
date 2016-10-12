/*\
 | ------------------------------------------------------
 | @file : TemplateContainerInt.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Int
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERINT_HPP_INCLUDED
#define TEMPLATECONTAINERINT_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../function.hpp"
#include "TemplateContainer.hpp"

    namespace core
    {
        class TemplateContainerInt : public TemplateContainer
        {
            public :
                             TemplateContainerInt(std::string name, int value);
                             ~TemplateContainerInt();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string mName;
                int         mValue;
        };
    }

#endif // TEMPLATECONTAINERINT_HPP_INCLUDED

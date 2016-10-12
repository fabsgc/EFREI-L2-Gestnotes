/*\
 | ------------------------------------------------------
 | @file : TemplateContainerDataVector.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : DataVector
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERDATAVECTOR_HPP_INCLUDED
#define TEMPLATECONTAINERDATAVECTOR_HPP_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include "../../../function.hpp"
#include "TemplateContainer.hpp"

    namespace core
    {
        class TemplateContainerDataVector : public TemplateContainer
        {
            public :
                             TemplateContainerDataVector(std::string name, const dataVector& value);
                             ~TemplateContainerDataVector();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string mName;
                dataVector  mValue;
        };
    }

#endif // TEMPLATECONTAINERDATAVECTOR_HPP_INCLUDED

/*\
 | ------------------------------------------------------
 | @file : TemplateContainerFloat.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Flottant
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERFLOAT_HPP_INCLUDED
#define TEMPLATECONTAINERFLOAT_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../function.hpp"
#include "TemplateContainer.hpp"

    namespace core
    {
        class TemplateContainerFloat : public TemplateContainer
        {
            public :
                             TemplateContainerFloat(std::string name, const float value);
                             ~TemplateContainerFloat();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string mName;
                float       mValue;
        };
    }

#endif // TEMPLATECONTAINERINT_HPP_INCLUDED

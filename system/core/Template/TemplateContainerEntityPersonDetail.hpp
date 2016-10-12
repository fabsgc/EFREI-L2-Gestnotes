/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityPersonDetail.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : PersonDetail est une entité représentant la table person_detail
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYPERSONDETAIL_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYPERSONDETAIL_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../app/entity/PersonDetail.hpp"
#include "../../../function.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerString.hpp"
#include "TemplateContainerInt.hpp"

    namespace core
    {
        class TemplateContainerEntityPersonDetail : public TemplateContainer
        {
            public :
                             TemplateContainerEntityPersonDetail(std::string name, const entity::PersonDetail & value);
                             ~TemplateContainerEntityPersonDetail();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string                  mName;
                const entity::PersonDetail & mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYPERSONDETAIL_HPP_INCLUDED

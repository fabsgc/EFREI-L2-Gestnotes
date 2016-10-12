/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityAdmin.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Admin est une entité représentant la table admin
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYADMIN_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYADMIN_HPP_INCLUDED

#include <iostream>
#include <string>
#include <utility>
#include "../../../function.hpp"
#include "../../../app/entity/Admin.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerEntityPersonDetail.hpp"
#include "TemplateContainerString.hpp"

    namespace core
    {
        class TemplateContainerEntityAdmin : public TemplateContainer
        {
            public :
                             TemplateContainerEntityAdmin(std::string name, const entity::Admin & value);
                             ~TemplateContainerEntityAdmin();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string           mName;
                entity::Admin mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYADMIN_HPP_INCLUDED

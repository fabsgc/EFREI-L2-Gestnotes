/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityContact.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Contact est une entité représentant la table contact
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYCONTACT_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYCONTACT_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../app/entity/Contact.hpp"
#include "../../../function.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerEntityPersonDetail.hpp"
#include "TemplateContainerString.hpp"

    namespace core
    {
        class TemplateContainerEntityContact : public TemplateContainer
        {
            public :
                             TemplateContainerEntityContact(std::string name, const entity::Contact & value);
                             ~TemplateContainerEntityContact();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string             mName;
                const entity::Contact & mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYCONTACT_HPP_INCLUDED

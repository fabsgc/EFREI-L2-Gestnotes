/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityTeacher.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Teacher est une entité représentant la table teacher
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYTEACHER_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYTEACHER_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../app/entity/Teacher.hpp"
#include "../../../function.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerEntityPersonDetail.hpp"
#include "TemplateContainerString.hpp"

    namespace core
    {
        class TemplateContainerEntityTeacher : public TemplateContainer
        {
            public :
                             TemplateContainerEntityTeacher(std::string name, const entity::Teacher & value);
                             ~TemplateContainerEntityTeacher();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string                mName;
                const entity::Teacher & mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYTEACHER_HPP_INCLUDED

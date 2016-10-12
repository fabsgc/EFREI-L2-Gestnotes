/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityGroup.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Group est une entité représentant la table groups
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYGROUP_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYGROUP_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../app/entity/Group.hpp"
#include "../../../function.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerVectorEntity.hpp"
#include "TemplateContainerEntityCourse.hpp"
#include "TemplateContainerEntityStudent.hpp"
#include "TemplateContainerString.hpp"
#include "TemplateContainerInt.hpp"

    namespace core
    {
        class TemplateContainerEntityGroup : public TemplateContainer
        {
            public :
                             TemplateContainerEntityGroup(std::string name, const entity::Group & value);
                             ~TemplateContainerEntityGroup();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string            mName;
                const entity::Group & mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYGROUP_HPP_INCLUDED

/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityCourse.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Course est une entité représentant la table course
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYCOURSE_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYCOURSE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../app/entity/Course.hpp"
#include "../../../function.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerVectorEntity.hpp"
#include "TemplateContainerEntityTeacher.hpp"
#include "TemplateContainerEntityCourse.hpp"
#include "TemplateContainerEntityStudent.hpp"
#include "TemplateContainerEntityGroup.hpp"
#include "TemplateContainerString.hpp"
#include "TemplateContainerInt.hpp"
#include "TemplateContainerFloat.hpp"

    namespace core
    {
        class TemplateContainerEntityCourse : public TemplateContainer
        {
            public :
                             TemplateContainerEntityCourse(std::string name, const entity::Course & value);
                             ~TemplateContainerEntityCourse();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string            mName;
                const entity::Course & mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYCOURSE_HPP_INCLUDED

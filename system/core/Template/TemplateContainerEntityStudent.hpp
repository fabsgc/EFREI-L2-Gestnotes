/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityStudent.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Student est une entité représentant la table student
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYSTUDENT_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYSTUDENT_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../app/entity/Student.hpp"
#include "../../../function.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerEntityContact.hpp"
#include "TemplateContainerEntityTeacher.hpp"
#include "TemplateContainerEntityPersonDetail.hpp"
#include "TemplateContainerString.hpp"
#include "TemplateContainerBool.hpp"
#include "TemplateContainerInt.hpp"

    namespace core
    {
        class TemplateContainerEntityStudent : public TemplateContainer
        {
            public :
                             TemplateContainerEntityStudent(std::string name, const entity::Student & value);
                             ~TemplateContainerEntityStudent();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string             mName;
                const entity::Student & mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYSTUDENT_HPP_INCLUDED

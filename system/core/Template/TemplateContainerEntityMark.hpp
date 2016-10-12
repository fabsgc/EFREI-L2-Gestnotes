/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityMark.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Mark est une entité représentant la table mark
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYMARK_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYMARK_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../app/entity/Mark.hpp"
#include "../../../function.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerEntityStudent.hpp"
#include "TemplateContainerEntityCourse.hpp"
#include "TemplateContainerFloat.hpp"
#include "TemplateContainerInt.hpp"


    namespace core
    {
        class TemplateContainerEntityMark : public TemplateContainer
        {
            public :
                             TemplateContainerEntityMark(std::string name, const entity::Mark & value);
                             ~TemplateContainerEntityMark();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string          mName;
                const entity::Mark & mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYMARK_HPP_INCLUDED

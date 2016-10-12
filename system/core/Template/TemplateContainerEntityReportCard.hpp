/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityReportCard.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : ReportCard est une entité représentant la table report_card
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERENTITYREPORTCARD_HPP_INCLUDED
#define TEMPLATECONTAINERENTITYREPORTCARD_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../app/entity/ReportCard.hpp"
#include "../../../function.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerEntityStudent.hpp"
#include "TemplateContainerFloat.hpp"
#include "TemplateContainerInt.hpp"

    namespace core
    {
        class TemplateContainerEntityReportCard : public TemplateContainer
        {
            public :
                             TemplateContainerEntityReportCard(std::string name, const entity::ReportCard & value);
                             ~TemplateContainerEntityReportCard();
                std::string  render() const;
                stringVector renderChild() const;

            private :
                std::string                mName;
                const entity::ReportCard & mValue;
        };
    }

#endif // TEMPLATECONTAINERENTITYREPORTCARD_HPP_INCLUDED

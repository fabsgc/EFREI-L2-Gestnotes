/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityReportCard.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : ReportCard est une entité représentant la table report_card
 | ------------------------------------------------------
\*/

#include "TemplateContainerEntityReportCard.hpp"

    namespace core
    {
        TemplateContainerEntityReportCard::TemplateContainerEntityReportCard(std::string name, const entity::ReportCard & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerEntityReportCard::render() const
        {
            std::string result = "$" + mName + " = array(); \n";

            {
                TemplateContainerInt t("id", mValue.id);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerEntityStudent t("student", mValue.student);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result += "$" + mName + *i;
                }
            }

            return result;
        }

        stringVector TemplateContainerEntityReportCard::renderChild() const
        {
            stringVector data;
            std::string result;

            {
                TemplateContainerInt t("id", mValue.id);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerEntityStudent t("student", mValue.student);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result = "['" + mName + "']" + *i;
                    data.push_back(result);
                }
            }

            return data;
        }

        TemplateContainerEntityReportCard::~TemplateContainerEntityReportCard()
        {

        }
    }

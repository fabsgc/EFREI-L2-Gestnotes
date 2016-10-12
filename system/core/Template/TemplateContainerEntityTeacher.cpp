/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityTeacher.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Teacher est une entité représentant la table teacher
 | ------------------------------------------------------
\*/

#include "TemplateContainerEntityTeacher.hpp"

    namespace core
    {
        TemplateContainerEntityTeacher::TemplateContainerEntityTeacher(std::string name, const entity::Teacher & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerEntityTeacher::render() const
        {
            std::string result = "$" + mName + " = array(); \n";

            {
                TemplateContainerString t("id", mValue.id);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("password", mValue.password);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerEntityPersonDetail t("personDetail", mValue.personDetail);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result += "$" + mName + *i;
                }
            }

            return result;
        }

        stringVector TemplateContainerEntityTeacher::renderChild() const
        {
            stringVector data;
            std::string result;

            result = "['" + mName + "'] = array(); \n";
            data.push_back(result);

            {
                TemplateContainerString t("id", mValue.id);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("password", mValue.password);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerEntityPersonDetail t("personDetail", mValue.personDetail);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result = "['" + mName + "']" + *i;
                    data.push_back(result);
                }
            }

            return data;
        }

        TemplateContainerEntityTeacher::~TemplateContainerEntityTeacher()
        {

        }
    }

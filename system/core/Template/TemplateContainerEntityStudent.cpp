/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityStudent.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Student est une entité représentant la table student
 | ------------------------------------------------------
\*/


#include "TemplateContainerEntityStudent.hpp"

    namespace core
    {
        TemplateContainerEntityStudent::TemplateContainerEntityStudent(std::string name, const entity::Student & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerEntityStudent::render() const
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
                TemplateContainerBool t("sucessYear", mValue.successYear);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerInt t("group", mValue.group);
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

            {
                TemplateContainerEntityContact t("contact", mValue.contact);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result += "$" + mName + *i;
                }
            }

            {
                TemplateContainerEntityTeacher t("teacher", mValue.teacher);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result += "$" + mName + *i;
                }
            }

            return result;
        }

        stringVector TemplateContainerEntityStudent::renderChild() const
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
                TemplateContainerBool t("sucessYear", mValue.successYear);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerInt t("group", mValue.group);
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

            {
                TemplateContainerEntityContact t("contact", mValue.contact);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result = "['" + mName + "']" + *i;
                    data.push_back(result);
                }
            }

            {
                TemplateContainerEntityTeacher t("teacher", mValue.teacher);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result = "['" + mName + "']" + *i;
                    data.push_back(result);
                }
            }

            return data;
        }

        TemplateContainerEntityStudent::~TemplateContainerEntityStudent()
        {

        }
    }

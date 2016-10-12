/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityMark.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Mark est une entité représentant la table mark
 | ------------------------------------------------------
\*/

#include "TemplateContainerEntityMark.hpp"

    namespace core
    {
        TemplateContainerEntityMark::TemplateContainerEntityMark(std::string name, const entity::Mark & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerEntityMark::render() const
        {
            std::string result = "$" + mName + " = array(); \n";

            {
                TemplateContainerFloat t("value", mValue.value);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerFloat t("coeff", mValue.coeff);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerInt t("type", mValue.type);
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

            {
                TemplateContainerEntityCourse t("course", mValue.course);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result += "$" + mName + *i;
                }
            }

            return result;
        }

        stringVector TemplateContainerEntityMark::renderChild() const
        {
            stringVector data;
            std::string result;

            result = "['" + mName + "'] = array(); \n";
            data.push_back(result);

            {
                TemplateContainerFloat t("value", mValue.value);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerFloat t("coeff", mValue.coeff);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerInt t("type", mValue.type);
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

            {
                TemplateContainerEntityCourse t("course", mValue.course);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result = "['" + mName + "']" + *i;
                    data.push_back(result);
                }
            }

            return data;
        }

        TemplateContainerEntityMark::~TemplateContainerEntityMark()
        {

        }
    }

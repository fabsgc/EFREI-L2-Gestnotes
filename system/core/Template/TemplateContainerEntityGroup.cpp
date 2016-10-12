/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityGroup.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Group est une entité représentant la table groups
 | ------------------------------------------------------
\*/

#include "TemplateContainerEntityGroup.hpp"

    namespace core
    {
        TemplateContainerEntityGroup::TemplateContainerEntityGroup(std::string name, const entity::Group & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerEntityGroup::render() const
        {
            std::string result = "$" + mName + " = array(); \n";
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityCourse>> vectorEntityCourse;
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityStudent>> vectorEntityStudent;

            {
                TemplateContainerInt t("id", mValue.id);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("name", mValue.name);
                result += "$" + mName + t.renderChild().front();
            }

            result += "$" + mName + "['students'] = array(); \n";

            {
                std::vector<TemplateContainerEntityStudent> data;
                int j = 0;

                for(auto i = mValue.students.begin(); i != mValue.students.end(); i++)
                {
                    TemplateContainerEntityStudent var(var2Str(j), *i);
                    data.push_back(var);
                    j++;
                }

                TemplateContainerVectorEntity<TemplateContainerEntityStudent> var("students", data);
                vectorEntityStudent.push_back(var);

                for(auto i = vectorEntityStudent.begin(); i != vectorEntityStudent.end(); i++)
                {
                    stringVector v = (*i).renderChild();

                    for(auto j = v.begin(); j != v.end(); j++)
                    {
                        result += "$" + mName + *j;
                    }
                }
            }

            return result;
        }

        stringVector TemplateContainerEntityGroup::renderChild() const
        {
            stringVector dataFinal;
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityCourse>> vectorEntityCourse;
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityStudent>> vectorEntityStudent;
            std::string result;

            result = "['" + mName + "'] = array(); \n";
            dataFinal.push_back(result);

            {
                TemplateContainerInt t("id", mValue.id);
                result = "['" + mName + "']" + t.renderChild().front();
                dataFinal.push_back(result);
            }

            {
                TemplateContainerString t("name", mValue.name);
                result = "['" + mName + "']" + t.renderChild().front();
                dataFinal.push_back(result);
            }

            result = "['" + mName + "']['students'] = array(); \n";
            dataFinal.push_back(result);

            {
                std::vector<TemplateContainerEntityStudent> data;
                int j = 0;

                for(auto i = mValue.students.begin(); i != mValue.students.end(); i++)
                {
                    TemplateContainerEntityStudent var(var2Str(j), *i);
                    data.push_back(var);
                    j++;
                }

                TemplateContainerVectorEntity<TemplateContainerEntityStudent> var("students", data);
                vectorEntityStudent.push_back(var);

                for(auto i = vectorEntityStudent.begin(); i != vectorEntityStudent.end(); i++)
                {
                    stringVector v = (*i).renderChild();

                    for(auto j = v.begin(); j != v.end(); j++)
                    {
                        result = "['" + mName + "']" + *j;
                        dataFinal.push_back(result);
                    }
                }
            }

            return dataFinal;
        }

        TemplateContainerEntityGroup::~TemplateContainerEntityGroup()
        {

        }
    }

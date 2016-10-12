/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityCourse.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Course est une entité représentant la table course
 | ------------------------------------------------------
\*/

#include "TemplateContainerEntityCourse.hpp"

    namespace core
    {
        TemplateContainerEntityCourse::TemplateContainerEntityCourse(std::string name, const entity::Course & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerEntityCourse::render() const
        {
            std::string result = "$" + mName + " = array(); \n";
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityTeacher>> vectorEntityTeacher;
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityStudent>> vectorEntityStudent;
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityGroup>> vectorEntityGroup;

            {
                TemplateContainerInt t("id", mValue.id);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("name", mValue.name);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerFloat t("coeffCe", mValue.coeffCe);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerFloat t("coeffDe", mValue.coeffDe);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerFloat t("coeffTp", mValue.coeffTp);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerFloat t("coeffProject", mValue.coeffProject);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerEntityTeacher t("teacherPrincipal", mValue.teacherPrincipal);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result += "$" + mName + *i;
                }
            }

            result += "$" + mName + "['teachersAssistant'] = array(); \n";

            {
                std::vector<TemplateContainerEntityTeacher> data;
                int j = 0;

                for(auto i = mValue.teachersAssistant.begin(); i != mValue.teachersAssistant.end(); i++)
                {
                    TemplateContainerEntityTeacher var(var2Str(j), *i);
                    data.push_back(var);
                    j++;
                }

                TemplateContainerVectorEntity<TemplateContainerEntityTeacher> var("teachersAssistant", data);
                vectorEntityTeacher.push_back(var);

                for(auto i = vectorEntityTeacher.begin(); i != vectorEntityTeacher.end(); i++)
                {
                    stringVector v = (*i).renderChild();

                    for(auto j = v.begin(); j != v.end(); j++)
                    {
                        result += "$" + mName + *j;
                    }
                }
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

            result += "$" + mName + "['groups'] = array(); \n";

            {
                std::vector<TemplateContainerEntityGroup> data;
                int j = 0;

                for(auto i = mValue.groups.begin(); i != mValue.groups.end(); i++)
                {
                    TemplateContainerEntityGroup var(var2Str(j), *i);
                    data.push_back(var);
                    j++;
                }

                TemplateContainerVectorEntity<TemplateContainerEntityGroup> var("groups", data);
                vectorEntityGroup.push_back(var);

                for(auto i = vectorEntityGroup.begin(); i != vectorEntityGroup.end(); i++)
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

        stringVector TemplateContainerEntityCourse::renderChild() const
        {
            stringVector dataFinal;
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityTeacher>> vectorEntityTeacher;
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityStudent>> vectorEntityStudent;
            std::vector<TemplateContainerVectorEntity<TemplateContainerEntityGroup>> vectorEntityGroup;
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

            {
                TemplateContainerFloat t("coeffCe", mValue.coeffCe);
                result = "['" + mName + "']" + t.renderChild().front();
                dataFinal.push_back(result);
            }

            {
                TemplateContainerFloat t("coeffDe", mValue.coeffDe);
                result = "['" + mName + "']" + t.renderChild().front();
                dataFinal.push_back(result);
            }

            {
                TemplateContainerFloat t("coeffTp", mValue.coeffTp);
                result = "['" + mName + "']" + t.renderChild().front();
                dataFinal.push_back(result);
            }

            {
                TemplateContainerFloat t("coeffProject", mValue.coeffProject);
                result = "['" + mName + "']" + t.renderChild().front();
                dataFinal.push_back(result);
            }

            {
                TemplateContainerEntityTeacher t("teacherPrincipal", mValue.teacherPrincipal);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result = "['" + mName + "']" + *i;
                    dataFinal.push_back(result);
                }
            }

            result = "['" + mName + "']['teachersAssistant'] = array(); \n";
            dataFinal.push_back(result);

            {
                std::vector<TemplateContainerEntityTeacher> data;
                int j = 0;

                for(auto i = mValue.teachersAssistant.begin(); i != mValue.teachersAssistant.end(); i++)
                {
                    TemplateContainerEntityTeacher var(var2Str(j), *i);
                    data.push_back(var);
                    j++;
                }

                TemplateContainerVectorEntity<TemplateContainerEntityTeacher> var("teachersAssistant", data);
                vectorEntityTeacher.push_back(var);

                for(auto i = vectorEntityTeacher.begin(); i != vectorEntityTeacher.end(); i++)
                {
                    stringVector v = (*i).renderChild();

                    for(auto j = v.begin(); j != v.end(); j++)
                    {
                        result = "['" + mName + "']" + *j;
                        dataFinal.push_back(result);
                    }
                }
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

            result = "['" + mName + "']['group'] = array(); \n";
            dataFinal.push_back(result);

            {
                std::vector<TemplateContainerEntityGroup> data;
                int j = 0;

                for(auto i = mValue.groups.begin(); i != mValue.groups.end(); i++)
                {
                    TemplateContainerEntityGroup var(var2Str(j), *i);
                    data.push_back(var);
                    j++;
                }

                TemplateContainerVectorEntity<TemplateContainerEntityGroup> var("groups", data);
                vectorEntityGroup.push_back(var);

                for(auto i = vectorEntityGroup.begin(); i != vectorEntityGroup.end(); i++)
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

        TemplateContainerEntityCourse::~TemplateContainerEntityCourse()
        {

        }
    }

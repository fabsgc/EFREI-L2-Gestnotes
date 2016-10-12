/*\
 | ------------------------------------------------------
 | @file : AdminCourseController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des cours par les administrateurs
 | ------------------------------------------------------
\*/

#include "AdminCourseController.hpp"

    namespace app
    {
        AdminCourseController::AdminCourseController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string AdminCourseController::home()
        {
            std::vector<entity::Course> courses = mModel.getCourses();

            core::Template tpl("adminCourse/home", "home", mConfig, mRequest);
            tpl.var("title", "Cours");
            tpl.var("filAriane", "Cours");
            tpl.var("courses", courses);

            return tpl.render();
        }

        std::string AdminCourseController::newCourse()
        {
            std::vector<entity::Teacher> teachers = mModel.getTeachers();
            std::vector<entity::Group> groups = mModel.getGroups();

            core::Template tpl("adminCourse/newCourse", "newCourse", mConfig, mRequest);
            tpl.var("title", "Nouveau cours");
            tpl.var("filAriane", "Cours/Nouveau cours");
            tpl.var("teachers", teachers);
            tpl.var("groups", groups);

            core::FormValidator form(mRequest, mDatabase);
            form.add("name", "nom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un nom à ce cours");
            form.add("coeff-ce", "CE", core::form::Type::input, core::form::Contraint::in, "0-0.1-0.2-0.3-0.4-0.5-0.6-0.7-0.8-0.9-1", "veuillez indiquer un coefficient valide");
            form.add("coeff-de", "DE", core::form::Type::input, core::form::Contraint::in, "0-0.1-0.2-0.3-0.4-0.5-0.6-0.7-0.8-0.9-1", "veuillez indiquer un coefficient valide");
            form.add("coeff-tp", "TP", core::form::Type::input, core::form::Contraint::in, "0-0.1-0.2-0.3-0.4-0.5-0.6-0.7-0.8-0.9-1", "veuillez indiquer un coefficient valide");
            form.add("coeff-project", "projet", core::form::Type::input, core::form::Contraint::in, "0-0.1-0.2-0.3-0.4-0.5-0.6-0.7-0.8-0.9-1", "veuillez indiquer un coefficient valide");
            form.add("teacher-principal", "professeur principal", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM teacher WHERE id = :input][==][1]", "ce professeur n'existe pas");
            form.add("teacher-assistant", "professeurs assistants", core::form::Type::selectMultiple, core::form::Contraint::sql, "[SELECT id FROM teacher WHERE id = :input][==][1]", "un ou plusieurs professeurs de la liste n'existent pas");
            form.add("teacher-assistant", "professeurs assistants", core::form::Type::selectMultiple, core::form::Contraint::different, mRequest.post("teacher-principal"), "un professeur principale ne peut pas être aussi assistant");
            form.add("group", "groupes", core::form::Type::selectMultiple, core::form::Contraint::sql, "[SELECT id FROM groups WHERE id = :input][==][1]", "un ou plusieurs groupes de la liste n'existent pas");
            form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

            if(form.sent())
            {
                float value = std::stof(mRequest.post("coeff-ce")) + std::stof(mRequest.post("coeff-de")) + std::stof(mRequest.post("coeff-tp")) + std::stof(mRequest.post("coeff-project"));

                if(value!= 1)
                {
                    form.add("coeffCe", "Coefficients", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), "La somme des coefficients ne fait pas 1");
                }
                    
                if(form.check())
                {
                    entity::Course course(mDatabase);

                    course.name = mRequest.post("name");
                    course.coeffCe = std::stof(mRequest.post("coeff-ce"));
                    course.coeffDe = std::stof(mRequest.post("coeff-de"));
                    course.coeffTp = std::stof(mRequest.post("coeff-tp"));
                    course.coeffProject = std::stof(mRequest.post("coeff-project"));
                    course.teacherPrincipal = mModel.getTeacherById(mRequest.post("teacher-principal"));

                    std::vector<std::string> teachersAssistant = splitString(mRequest.post("teacher-assistant"), "-");

                    for(auto i = teachers.begin(); i != teachers.end(); i++)
                    {
                        if(isset(teachersAssistant, var2Str(i->id)))
                        {
                            course.teachersAssistant.push_back(*i);
                        }
                    }

                    std::vector<std::string> groupsList = splitString(mRequest.post("group"), "-");

                    for(auto i = groups.begin(); i != groups.end(); i++)
                    {
                        if(isset(groupsList, var2Str(i->id)))
                        {
                            course.groups.push_back(*i);
                        }
                    }

                    course.save();

                    std::cout << redirect(mUrl.get("admin-course"));
                    mSession.set("flash_success", "Le cours \"" + course.name + "\" a bien été créé");

                    return "";
                }
                else
                {
                    tpl.var("formErrors", form.getErrors());
                }
            }

            return tpl.render();
        }

        std::string AdminCourseController::editCourse()
        {
            entity::Course course = mModel.getCourseById(mRequest.get()["id"]);

            if(course.validEntity == true)
            {
                std::vector<entity::Teacher> teachers = mModel.getTeachers();
                std::vector<entity::Group> groups = mModel.getGroups();

                core::Template tpl("adminCourse/editCourse", "editCourse", mConfig, mRequest);
                tpl.var("title", "Éditer un cours");
                tpl.var("filAriane", "Groupe/Éditer un cours/" + course.name);
                tpl.var("course", course);
                tpl.var("groups", groups);
                tpl.var("teachers", teachers);

                std::vector<std::string> teacherAssistantInCourse;
                std::vector<std::string> groupInCourse;

                for(auto i = course.teachersAssistant.begin(); i != course.teachersAssistant.end(); i++)
                {
                    teacherAssistantInCourse.push_back(i->id);
                }

                for(auto i = course.groups.begin(); i != course.groups.end(); i++)
                {
                    groupInCourse.push_back(var2Str(i->id));
                }

                tpl.var("teacherAssistantInCourse", teacherAssistantInCourse);
                tpl.var("groupInCourse", groupInCourse);

                core::FormValidator form(mRequest, mDatabase);
                form.add("name", "nom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un nom à ce cours");
                form.add("coeff-ce", "CE", core::form::Type::input, core::form::Contraint::in, "0-0.1-0.2-0.3-0.4-0.5-0.6-0.7-0.8-0.9-1", "veuillez indiquer un coefficient valide");
                form.add("coeff-de", "DE", core::form::Type::input, core::form::Contraint::in, "0-0.1-0.2-0.3-0.4-0.5-0.6-0.7-0.8-0.9-1", "veuillez indiquer un coefficient valide");
                form.add("coeff-tp", "TP", core::form::Type::input, core::form::Contraint::in, "0-0.1-0.2-0.3-0.4-0.5-0.6-0.7-0.8-0.9-1", "veuillez indiquer un coefficient valide");
                form.add("coeff-project", "projet", core::form::Type::input, core::form::Contraint::in, "0-0.1-0.2-0.3-0.4-0.5-0.6-0.7-0.8-0.9-1", "veuillez indiquer un coefficient valide");
                form.add("teacher-principal", "professeur principal", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM teacher WHERE id = :input][==][1]", "ce professeur n'existe pas");
                form.add("teacher-assistant", "professeurs assistants", core::form::Type::selectMultiple, core::form::Contraint::sql, "[SELECT id FROM teacher WHERE id = :input][==][1]", "un ou plusieurs professeurs de la liste n'existent pas");
                form.add("teacher-assistant", "professeurs assistants", core::form::Type::selectMultiple, core::form::Contraint::different, mRequest.post("teacher-principal"), "un professeur principale ne peut pas être aussi assistant");
                form.add("group", "groupes", core::form::Type::selectMultiple, core::form::Contraint::sql, "[SELECT id FROM groups WHERE id = :input][==][1]", "un ou plusieurs groupes de la liste n'existent pas");
                form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

                if(form.sent())
                {
                    float value = std::stof(mRequest.post("coeff-ce")) + std::stof(mRequest.post("coeff-de")) + std::stof(mRequest.post("coeff-tp")) + std::stof(mRequest.post("coeff-project"));

                    if(value!= 1)
                    {
                        form.add("coeffCe", "Coefficients", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), "La somme des coefficients ne fait pas 1");
                    }

                    if(form.check())
                    {
                        course.name = mRequest.post("name");
                        course.coeffCe = std::stof(mRequest.post("coeff-ce"));
                        course.coeffDe = std::stof(mRequest.post("coeff-de"));
                        course.coeffTp = std::stof(mRequest.post("coeff-tp"));
                        course.coeffProject = std::stof(mRequest.post("coeff-project"));
                        course.teacherPrincipal = mModel.getTeacherById(mRequest.post("teacher-principal"));

                        std::vector<std::string> teachersAssistant = splitString(mRequest.post("teacher-assistant"), "-");
                        course.teachersAssistant.clear();

                        for(auto i = teachers.begin(); i != teachers.end(); i++)
                        {
                            if(isset(teachersAssistant, var2Str(i->id)))
                            {
                                course.teachersAssistant.push_back(*i);
                            }
                        }

                        std::vector<std::string> groupsList = splitString(mRequest.post("group"), "-");
                        course.groups.clear();

                        for(auto i = groups.begin(); i != groups.end(); i++)
                        {
                            if(isset(groupsList, var2Str(i->id)))
                            {
                                course.groups.push_back(*i);
                            }
                        }

                        course.update();

                        std::cout << redirect(mUrl.get("admin-course"));
                        mSession.set("flash_success", "Le cours \"" + course.name + "\" a bien été édité");

                        return "";
                    }
                    else
                    {
                        tpl.var("formErrors", form.getErrors());
                    }
                }

                return tpl.render();
            }

            std::cout << redirect404();
            return "status:404";
        }

        std::string AdminCourseController::deleteCourse()
        {
            entity::Course course = mModel.getCourseById(mRequest.get()["id"]);

            if(course.validEntity == true)
            {
                course.destroy();

                std::cout << redirect(mUrl.get("admin-course"));
                mSession.set("flash_success", "le course a bien été supprimé");
                return "";
            }

            return "status:404";
        }
    }

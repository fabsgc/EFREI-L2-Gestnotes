/*\
 | ------------------------------------------------------
 | @file : AdminGroupController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des groupes par les administrateurs
 | ------------------------------------------------------
\*/

#include "AdminGroupController.hpp"

    namespace app
    {
        AdminGroupController::AdminGroupController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string AdminGroupController::home()
        {
            std::vector<entity::Group> groups = mModel.getGroups();

            core::Template tpl("adminGroup/home", "home", mConfig, mRequest);
            tpl.var("title", "Groupes");
            tpl.var("filAriane", "Groupes");
            tpl.var("groups", groups);
            return tpl.render();
        }

        std::string AdminGroupController::newGroup()
        {
            std::vector<entity::Student> studentsNotInGroup = mModel.getStudentsNotInGroup();

            core::Template tpl("adminGroup/newGroup", "newGroup", mConfig, mRequest);
            tpl.var("title", "Nouveau professeur");
            tpl.var("filAriane", "Groupe/Nouveau groupe");
            tpl.var("studentsNotInGroup", studentsNotInGroup);

            core::FormValidator form(mRequest, mDatabase);
            form.add("name", "nom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un nom à ce groupe");
            form.add("student", "Elèves", core::form::Type::selectMultiple, core::form::Contraint::sql, "[SELECT id FROM student WHERE id = :input][==][1]", "un ou plusieurs élèves de la liste n'existent pas");
            form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

            if(form.sent())
            {
                if(form.check())
                {
                    entity::Group group(mDatabase);

                    group.name = mRequest.post("name");

                    std::vector<std::string> students = splitString(mRequest.post("student"), "-");

                    for(auto i = studentsNotInGroup.begin(); i != studentsNotInGroup.end(); i++)
                    {
                        if(isset(students, var2Str(i->id)))
                        {
                            group.students.push_back(*i);
                        }
                    }

                    group.save();

                    std::cout << redirect(mUrl.get("admin-group"));
                    mSession.set("flash_success", "Le groupe \"" + group.name + "\" a bien été créé");

                    return "";
                }
                else
                {
                    tpl.var("formErrors", form.getErrors());
                }
            }

            return tpl.render();
        }

        std::string AdminGroupController::editGroup()
        {
            entity::Group group = mModel.getGroupById(mRequest.get()["id"]);

            if(group.validEntity == true)
            {
                std::vector<entity::Student> studentsNotInGroupAndThisGroup = mModel.getStudentsNotInGroupAndThisGroup(var2Str(group.id));
                std::vector<entity::Student> studentsThisGroup = mModel.getStudentsThisGroup(var2Str(group.id));

                core::Template tpl("adminGroup/editGroup", "editGroup", mConfig, mRequest);
                tpl.var("title", "Éditer un groupe");
                tpl.var("filAriane", "Groupe/Éditer un groupe/" + group.name);
                tpl.var("studentsNotInGroupAndThisGroup", studentsNotInGroupAndThisGroup);
                tpl.var("group", group);

                std::vector<std::string> students;

                for(auto i = studentsThisGroup.begin(); i != studentsThisGroup.end(); i++)
                {
                    students.push_back(i->id);
                }

                tpl.var("studentsThisGroup", students);

                core::FormValidator form(mRequest, mDatabase);
                form.add("name", "nom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un nom à ce groupe");
                form.add("student", "Elèves", core::form::Type::selectMultiple, core::form::Contraint::sql, "[SELECT id FROM student WHERE id = :input][==][1]", "Un ou plusieurs élèves de la liste n'existe pas");
                form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

                if(form.sent())
                {
                    if(form.check())
                    {
                        group.name = mRequest.post("name");
                        group.students.clear();

                        students = splitString(mRequest.post("student"), "-");

                        for(auto i = studentsNotInGroupAndThisGroup.begin(); i != studentsNotInGroupAndThisGroup.end(); i++)
                        {
                            if(isset(students, var2Str(i->id)))
                            {
                                group.students.push_back(*i);
                            }
                        }

                        group.update();

                        std::cout << redirect(mUrl.get("admin-group"));
                        mSession.set("flash_success", "Le groupe \"" + group.name + "\" a bien été édité");

                        return "";
                    }
                    else
                    {
                        tpl.var("formErrors", form.getErrors());
                    }
                }

                return tpl.render();
            }

            return "status:404";
        }

        std::string AdminGroupController::deleteGroup()
        {
            entity::Group group = mModel.getGroupById(mRequest.get()["id"]);

            if(group.validEntity == true)
            {
                group.destroy();

                std::cout << redirect(mUrl.get("admin-group"));
                mSession.set("flash_success", "le groupe a bien été supprimé");
                return "";
            }

            return "status:404";
        }

        std::string AdminGroupController::seeGroup()
        {
            entity::Group group = mModel.getGroupById(mRequest.get()["id"]);
            std::vector<entity::Student> students = mModel.getStudentsThisGroup(var2Str(group.id));

            core::Template tpl("adminGroup/seeGroup", "seeGroup", mConfig, mRequest);
            tpl.var("title", group.name);
            tpl.var("filAriane", "Groupes/"+group.name);
            tpl.var("group", group);
            tpl.var("students", students);
            return tpl.render();
        }
    }

/*\
 | ------------------------------------------------------
 | @file : AdminTeacherController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des professeurs par les administrateurs
 | ------------------------------------------------------
\*/

#include "AdminTeacherController.hpp"

    namespace app
    {
        AdminTeacherController::AdminTeacherController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string AdminTeacherController::home()
        {
            std::vector<entity::Teacher> teachers;
            teachers = mModel.getTeachers();

            core::Template tpl("adminTeacher/home", "home", mConfig, mRequest);
            tpl.var("title", "Professeur");
            tpl.var("filAriane", "Professeur");
            tpl.var("teachers", teachers);

            return tpl.render();
        }

        std::string AdminTeacherController::newTeacher()
        {
            core::Template tpl("adminTeacher/newTeacher", "newTeacher", mConfig, mRequest);
            tpl.var("title", "Nouveau professeur");
            tpl.var("filAriane", "Professeur/Nouveau professeur");

            core::FormValidator form(mRequest, mDatabase);
            form.add("name", "nom", core::form::Type::input, core::form::Contraint::different, "a", "veuillez donner un nom à ce professeur");
            form.add("firstname", "prénom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un prénom à ce professeur");
            form.add("email", "email", core::form::Type::input, core::form::Contraint::email, "", "veuillez donner l'email de ce professeur");
            form.add("email", "email", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM person_detail WHERE email = :input][==][0]", "veuillez donner l'email de ce professeur");
            form.add("address", "adresse", core::form::Type::input, core::form::Contraint::different, "", "veuillez une adresse valide");
            form.add("postalCode", "code postal", core::form::Type::input, core::form::Contraint::match, "[a-zA-Z0-9]+", "veuillez donner un code postal valide");
            form.add("country", "pays", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer son pays");
            form.add("city", "ville", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer votre ville");
            form.add("phone-home", "téléphone fixe", core::form::Type::input, core::form::Contraint::match, "^0[1-9][0-9]{8}$", "veuillez saisir un numéro de téléphone valide");
            form.add("phone-mobile", "téléphone mobile", core::form::Type::input, core::form::Contraint::match, "^0[1-9][0-9]{8}$", "veuillez saisir un numéro de mobile valide");
            form.add("date-born", "date de naissance", core::form::Type::input, core::form::Contraint::match, "[0-9]{2}/[0-9]{2}/[0-9]{4}", "veuillez indiquer sa date de naissance");
            form.add("gender", "sexe", core::form::Type::input, core::form::Contraint::in, "0-1", "veuillez indiquer son sexe");
            form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

            if(form.sent())
            {
                if(form.check())
                {
                    entity::Teacher teacher(mDatabase);
                    int id = mModel.getLastTeacherId() + 1;
                    teacher.id = "teacher" + var2Str(id);

                    teacher.personDetail.name = mRequest.post("name");
                    teacher.personDetail.firstName = mRequest.post("firstname");
                    teacher.personDetail.email = mRequest.post("email");
                    teacher.personDetail.address = mRequest.post("address");
                    teacher.personDetail.city = mRequest.post("city");
                    teacher.personDetail.postalCode = mRequest.post("postalCode");
                    teacher.personDetail.country = mRequest.post("country");
                    teacher.personDetail.avatar = "/public/img/avatar.png";
                    teacher.personDetail.phoneHome = mRequest.post("phone-home");
                    teacher.personDetail.phoneMobile = mRequest.post("phone-mobile");
                    teacher.personDetail.dateBorn = mRequest.post("date-born");
                    teacher.personDetail.dateRegister = "25/05/2015";
                    teacher.personDetail.gender = std::stoi(mRequest.post("gender"));
                    teacher.password = getSha1("mdpmdp");

                    teacher.save();

                    std::cout << redirect(mUrl.get("admin-teacher"));
                    mSession.set("flash_success", "Le professeur " + teacher.personDetail.firstName + " " + teacher.personDetail.name + " a bien été créé");

                    return "";
                }
                else
                {
                    tpl.var("formErrors", form.getErrors());
                }
            }

            return tpl.render();
        }

        std::string AdminTeacherController::editTeacher()
        {
            entity::Teacher teacher = mModel.getTeacherById(mRequest.get()["id"]);

            if(teacher.validEntity == true)
            {
                core::Template tpl("adminTeacher/editTeacher", "editTeacher", mConfig, mRequest);
                tpl.var("title", "Éditer un professeur");
                tpl.var("filAriane", "Professeur/Éditer la fiche d'un élève/" + teacher.personDetail.firstName + " - " + teacher.personDetail.name);
                tpl.var("teacher", teacher);

                core::FormValidator form(mRequest, mDatabase);
                form.add("name", "nom", core::form::Type::input, core::form::Contraint::different, "a", "veuillez donner un nom à cet élève");
                form.add("firstname", "prénom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un prénom à cet élève");
                form.add("email", "email", core::form::Type::input, core::form::Contraint::email, "", "veuillez donner l'email de ce professeur");
                form.add("email", "email", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM person_detail WHERE email = :input and id != " + var2Str(teacher.personDetail.id) + "][==][0]", "cet email est déjà utilisé par un autre professeur");
                form.add("address", "adresse", core::form::Type::input, core::form::Contraint::different, "", "veuillez une adresse valide");
                form.add("postalCode", "code postal", core::form::Type::input, core::form::Contraint::match, "[a-zA-Z0-9]+", "veuillez donner un code postal valide");
                form.add("country", "pays", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer son pays");
                form.add("city", "ville", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer votre ville");
                form.add("phone-home", "téléphone fixe", core::form::Type::input, core::form::Contraint::match, "^0[1-9][0-9]{8}$", "veuillez saisir un numéro de téléphone valide");
                form.add("phone-mobile", "téléphone mobile", core::form::Type::input, core::form::Contraint::match, "^0[1-9][0-9]{8}$", "veuillez saisir un numéro de mobile valide");
                form.add("date-born", "date de naissance", core::form::Type::input, core::form::Contraint::match, "[0-9]{2}/[0-9]{2}/[0-9]{4}", "veuillez indiquer sa date de naissance");
                form.add("gender", "sexe", core::form::Type::input, core::form::Contraint::in, "0-1", "veuillez indiquer son sexe");
                form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

                if(form.sent())
                {
                    if(form.check())
                    {
                        teacher.personDetail.name = mRequest.post("name");
                        teacher.personDetail.firstName = mRequest.post("firstname");
                        teacher.personDetail.email = mRequest.post("email");
                        teacher.personDetail.address = mRequest.post("address");
                        teacher.personDetail.city = mRequest.post("city");
                        teacher.personDetail.postalCode = mRequest.post("postalCode");
                        teacher.personDetail.country = mRequest.post("country");
                        teacher.personDetail.avatar = "/public/img/avatar.png";
                        teacher.personDetail.phoneHome = mRequest.post("phone-home");
                        teacher.personDetail.phoneMobile = mRequest.post("phone-mobile");
                        teacher.personDetail.dateBorn = mRequest.post("date-born");
                        teacher.personDetail.dateRegister = "25/05/2015";
                        teacher.personDetail.gender = std::stoi(mRequest.post("gender"));
                        teacher.update();

                        std::cout << redirect(mUrl.get("admin-teacher"));
                        mSession.set("flash_success", "Le professeur " + teacher.personDetail.firstName + " " + teacher.personDetail.name + " a bien été édité");

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

        std::string AdminTeacherController::deleteTeacher()
        {
            //Si il est assistant professeur, on dégage la ligne
            //Si il est professeur principale, on indique les matières
            //Si il a des étudiants qui lui sont liés, on indique lesquels
            entity::Teacher teacher = mModel.getTeacherById(mRequest.get()["id"]);
            std::string flash;

            if(teacher.validEntity == true)
            {
                std::vector<entity::Course> courses = mModel.getCoursesTeacher(teacher.id);
                std::vector<entity::Student> students = mModel.getStudentsTeacher(teacher.id);

                if(courses.size() == 0 && students.size() == 0)
                {
                    teacher.destroy();

                    std::cout << redirect(mUrl.get("admin-teacher"));
                    mSession.set("flash_success", "Le professeur " + teacher.personDetail.firstName + " " + teacher.personDetail.name + " a bien été supprimé");
                    return "";
                }
                else
                {
                    if(courses.size() > 0)
                    {
                        flash += "Ce professeur est professeur principale : ";

                        for(auto i = courses.begin(); i != courses.end(); i++)
                        {
                            flash += " " + i->name + ",";
                        }

                        if(students.size() > 0)
                        {
                            flash += "<br />";
                        }
                    }

                    if(students.size() > 0)
                    {
                        flash += "Ce professeur est référent d'élèves : ";

                        for(auto i = students.begin(); i != students.end(); i++)
                        {
                            flash += " " + i->personDetail.firstName + " " + i->personDetail.name + ",";
                        }
                    }

                    std::cout << redirect(mUrl.get("admin-teacher"));
                    mSession.set("flash_success", flash);
                    return "";
                }
            }

            return "status:404";
        }

        std::string AdminTeacherController::seeTeacher()
        {
            entity::Teacher teacher = mModel.getTeacherById(mRequest.get()["id"]);

            if(teacher.validEntity == true)
            {
                core::Template tpl("adminTeacher/seeTeacher", "seeTeacher", mConfig, mRequest);
                tpl.var("title", teacher.personDetail.firstName + " - " + teacher.personDetail.name);
                tpl.var("filAriane", "Professeur/" + teacher.personDetail.firstName + " - " + teacher.personDetail.name);
                tpl.var("teacher", teacher);

                return tpl.render();
            }

            return "status:404";
        }
    }

/*\
 | ------------------------------------------------------
 | @file : AdminStudentController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des élèves par les administrateurs
 | ------------------------------------------------------
\*/

#include "AdminStudentController.hpp"

    namespace app
    {
        AdminStudentController::AdminStudentController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string AdminStudentController::home()
        {
            std::vector<entity::Student> students;

            if(isset(mRequest.get(), "search"))
            {
                students = mModel.getStudents(mRequest.get("search"));
            }
            else
            {
                students = mModel.getStudents();
            }

            core::Template tpl("adminStudent/home", "home", mConfig, mRequest);
            tpl.var("title", "Élèves");
            tpl.var("filAriane", "Élèves");
            tpl.var("students", students);

            return tpl.render();
        }

        std::string AdminStudentController::newStudent()
        {
            std::vector<entity::Contact> contacts = mModel.getContacts();
            std::vector<entity::Teacher> teachers = mModel.getTeachers();
            core::Template tpl("adminStudent/newStudent", "newStudent", mConfig, mRequest);
            tpl.var("title", "Nouvel élève");
            tpl.var("filAriane", "Élèves/Nouvel élève");
            tpl.var("contacts", contacts);
            tpl.var("teachers", teachers);

            core::FormValidator form(mRequest, mDatabase);
            form.add("name", "nom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un nom à cet élève");
            form.add("firstname", "prénom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un prénom à cet élève");
            form.add("email", "email", core::form::Type::input, core::form::Contraint::email, "", "veuillez donner l'email de l'élève");
            form.add("email", "email", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM person_detail WHERE email = :input][==][0]", "cet email est déjà utilisé par un autre élève");
            form.add("address", "adresse", core::form::Type::input, core::form::Contraint::different, "", "veuillez une adresse valide");
            form.add("postalCode", "code postal", core::form::Type::input, core::form::Contraint::match, "[a-zA-Z0-9]+", "veuillez donner un code postal valide");
            form.add("country", "pays", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer son pays");
            form.add("city", "ville", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer votre ville");
            form.add("teacher", "professeur", core::form::Type::select, core::form::Contraint::sql, "[SELECT id FROM teacher WHERE id = :input][==][1]", "ce professeur n'existe pas");
            form.add("phone-home", "téléphone fixe", core::form::Type::input, core::form::Contraint::match, "^0[1-9][0-9]{8}$", "veuillez saisir un numéro de téléphone valide");
            form.add("phone-mobile", "téléphone mobile", core::form::Type::input, core::form::Contraint::match, "^0[1-9][0-9]{8}$", "veuillez saisir un numéro de mobile valide");
            form.add("date-born", "date de naissance", core::form::Type::input, core::form::Contraint::match, "[0-9]{2}/[0-9]{2}/[0-9]{4}", "veuillez indiquer sa date de naissance");
            form.add("gender", "sexe", core::form::Type::input, core::form::Contraint::in, "0-1", "veuillez indiquer son sexe");

            form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

            if(isset(mRequest.post(), var2Str("contact")) && mRequest.post("contact") == "0")
            {
                form.add("contact-name", "nom du contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner le nom du contact");
                form.add("contact-firstname", "prénom du contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner le prénom du contact");
                form.add("contact-email", "email du contact", core::form::Type::input, core::form::Contraint::email, "", "veuillez donner l'email du contact");
                form.add("contact-address", "adresse du contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner une adresse valide");
                form.add("contact-postalCode", "code postal du contact", core::form::Type::input, core::form::Contraint::match, "[a-zA-Z0-9]+", "veuillez donner un code postal valide");
                form.add("contact-city", "ville du contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer sa ville");
                form.add("contact-country", "pays du contact contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer son pays");
                form.add("contact-phone-home", "téléphone fixe contact", core::form::Type::input, core::form::Contraint::match, "^0[1-68][0-9]{8}$", "veuillez saisir un numéro de téléphone valide");
                form.add("contact-phone-mobile", "téléphone mobile contact", core::form::Type::input, core::form::Contraint::match, "^0[1-68][0-9]{8}$", "veuillez saisir un numéro de mobile valide");
                form.add("contact-gender", "sexe contact", core::form::Type::input, core::form::Contraint::in, "0-1", "veuillez indiquer son sexe");
            }
            else
            {
                form.add("contact", "contact", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM contact WHERE id = :input][==][1]", "ce contact n'existe pas");
            }

            if(form.sent())
            {
                if(form.check())
                {
                    entity::Student student(mDatabase);
                    int id = mModel.getLastUserId() + 1;
                    student.id = var2Str(id);

                    student.personDetail.name = mRequest.post("name");
                    student.personDetail.firstName = mRequest.post("firstname");
                    student.personDetail.email = mRequest.post("email");
                    student.personDetail.address = mRequest.post("address");
                    student.personDetail.city = mRequest.post("city");
                    student.personDetail.postalCode = mRequest.post("postalCode");
                    student.personDetail.country = mRequest.post("country");
                    student.personDetail.avatar = "/public/img/avatar.png";
                    student.personDetail.phoneHome = mRequest.post("phone-home");
                    student.personDetail.phoneMobile = mRequest.post("phone-mobile");
                    student.personDetail.dateBorn = mRequest.post("date-born");
                    student.personDetail.dateRegister = "25/05/2015";
                    student.personDetail.gender = std::stoi(mRequest.post("gender"));
                    student.password = getSha1("mdpmdp");
                    student.teacher = mModel.getTeacherById(mRequest.post("teacher"));
                    student.successYear = false;
                    student.group = 0;

                    if(isset(mRequest.post(), var2Str("contact")) && mRequest.post("contact") == "0")
                    {
                        student.contact.password = "";
                        student.contact.personDetail.name = mRequest.post("contact-name");
                        student.contact.personDetail.firstName = mRequest.post("contact-firstname");
                        student.contact.personDetail.email = mRequest.post("contact-email");
                        student.contact.personDetail.address = mRequest.post("contact-address");
                        student.contact.personDetail.city = mRequest.post("contact-city");
                        student.contact.personDetail.postalCode = mRequest.post("contact-postalCode");
                        student.contact.personDetail.country = mRequest.post("contact-country");
                        student.contact.personDetail.avatar = "";
                        student.contact.personDetail.phoneHome = mRequest.post("contact-phone-home");
                        student.contact.personDetail.phoneMobile = mRequest.post("contact-phone-mobile");
                        student.contact.personDetail.dateBorn = "";
                        student.contact.personDetail.dateRegister = "";
                        student.contact.personDetail.gender = std::stoi(mRequest.post("contact-gender"));
                        student.contact.save();
                    }
                    else
                    {
                        student.contact = mModel.getContactById(mRequest.post("contact"));
                    }

                    student.save();

                    std::cout << redirect(mUrl.get("admin-student"));
                    mSession.set("flash_success", "L'élève " + student.personDetail.firstName + " " + student.personDetail.name + " a bien été créé");

                    return "";
                }
                else
                {
                    tpl.var("formErrors", form.getErrors());
                }
            }

            return tpl.render();
        }

        std::string AdminStudentController::editStudent()
        {
            std::vector<entity::Contact> contacts = mModel.getContacts();
            std::vector<entity::Teacher> teachers = mModel.getTeachers();
            entity::Student student = mModel.getStudentById(mRequest.get()["id"]);

            if(student.validEntity == true)
            {
                core::Template tpl("adminStudent/editStudent", "editStudent", mConfig, mRequest);
                tpl.var("title", "Éditer la fiche d'un élève");
                tpl.var("filAriane", "Élèves/Éditer la fiche d'un élève/" + student.personDetail.firstName + " - " + student.personDetail.name);
                tpl.var("student", student);
                tpl.var("contacts", contacts);
                tpl.var("teachers", teachers);

                core::FormValidator form(mRequest, mDatabase);
                form.add("name", "nom", core::form::Type::input, core::form::Contraint::different, "a", "veuillez donner un nom à cet élève");
                form.add("firstname", "prénom", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner un prénom à cet élève");
                form.add("email", "email", core::form::Type::input, core::form::Contraint::email, "", "veuillez donner l'email de l'élève");
                form.add("email", "email", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM person_detail WHERE email = :input AND id != " + var2Str(student.personDetail.id) + "][==][0]", "cet email est déjà utilisé par un autre élève");
                form.add("address", "adresse", core::form::Type::input, core::form::Contraint::different, "", "veuillez une adresse valide");
                form.add("postalCode", "code postal", core::form::Type::input, core::form::Contraint::match, "[a-zA-Z0-9]+", "veuillez donner un code postal valide");
                form.add("country", "pays", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer son pays");
                form.add("city", "ville", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer votre ville");
                form.add("teacher", "professeur", core::form::Type::select, core::form::Contraint::sql, "[SELECT id FROM teacher WHERE id = :input][==][1]", "ce professeur n'existe pas");
                form.add("phone-home", "téléphone fixe", core::form::Type::input, core::form::Contraint::match, "^0[1-9][0-9]{8}$", "veuillez saisir un numéro de téléphone valide");
                form.add("phone-mobile", "téléphone mobile", core::form::Type::input, core::form::Contraint::match, "^0[1-9][0-9]{8}$", "veuillez saisir un numéro de mobile valide");
                form.add("date-born", "date de naissance", core::form::Type::input, core::form::Contraint::match, "[0-9]{2}/[0-9]{2}/[0-9]{4}", "veuillez indiquer sa date de naissance");
                form.add("gender", "sexe", core::form::Type::input, core::form::Contraint::in, "0-1", "veuillez indiquer son sexe");

                form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

                if(isset(mRequest.post(), var2Str("contact")) && mRequest.post("contact") == student.contact.id)
                {
                    form.add("contact-name", "nom du contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner le nom du contact");
                    form.add("contact-firstname", "prénom du contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner le prénom du contact");
                    form.add("contact-email", "email du contact", core::form::Type::input, core::form::Contraint::email, "", "veuillez donner l'email du contact");
                    form.add("contact-address", "adresse du contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez donner une adresse valide");
                    form.add("contact-postalCode", "code postal du contact", core::form::Type::input, core::form::Contraint::match, "[a-zA-Z0-9]+", "veuillez donner un code postal valide");
                    form.add("contact-city", "ville du contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer sa ville");
                    form.add("contact-country", "pays du contact contact", core::form::Type::input, core::form::Contraint::different, "", "veuillez indiquer son pays");
                    form.add("contact-phone-home", "téléphone fixe contact", core::form::Type::input, core::form::Contraint::match, "^0[1-68][0-9]{8}$", "veuillez saisir un numéro de téléphone valide");
                    form.add("contact-phone-mobile", "téléphone mobile contact", core::form::Type::input, core::form::Contraint::match, "^0[1-68][0-9]{8}$", "veuillez saisir un numéro de mobile valide");
                    form.add("contact-gender", "sexe contact", core::form::Type::input, core::form::Contraint::in, "0-1", "veuillez indiquer son sexe");
                }
                else
                {
                    form.add("contact", "contact", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM contact WHERE id = :input][==][1]", "ce contact n'existe pas");
                }


                if(form.sent())
                {
                    if(form.check())
                    {
                        student.personDetail.name = mRequest.post("name");
                        student.personDetail.firstName = mRequest.post("firstname");
                        student.personDetail.email = mRequest.post("email");
                        student.personDetail.address = mRequest.post("address");
                        student.personDetail.city = mRequest.post("city");
                        student.personDetail.postalCode = mRequest.post("postalCode");
                        student.personDetail.country = mRequest.post("country");
                        student.personDetail.avatar = "/public/img/avatar.png";
                        student.personDetail.phoneHome = mRequest.post("phone-home");
                        student.personDetail.phoneMobile = mRequest.post("phone-mobile");
                        student.personDetail.dateBorn = mRequest.post("date-born");
                        student.personDetail.dateRegister = "25/05/2015";
                        student.personDetail.gender = std::stoi(mRequest.post("gender"));
                        student.teacher = mModel.getTeacherById(mRequest.post("teacher"));

                        if(isset(mRequest.post(), var2Str("contact")) && mRequest.post("contact") == student.contact.id)
                        {
                            student.contact.id = mRequest.post("contact");
                            student.contact.password = "";
                            student.contact.personDetail.name = mRequest.post("contact-name");
                            student.contact.personDetail.firstName = mRequest.post("contact-firstname");
                            student.contact.personDetail.email = mRequest.post("contact-email");
                            student.contact.personDetail.address = mRequest.post("contact-address");
                            student.contact.personDetail.city = mRequest.post("contact-city");
                            student.contact.personDetail.postalCode = mRequest.post("contact-postalCode");
                            student.contact.personDetail.country = mRequest.post("contact-country");
                            student.contact.personDetail.avatar = "";
                            student.contact.personDetail.phoneHome = mRequest.post("contact-phone-home");
                            student.contact.personDetail.phoneMobile = mRequest.post("contact-phone-mobile");
                            student.contact.personDetail.dateBorn = "";
                            student.contact.personDetail.dateRegister = "";
                            student.contact.personDetail.gender = std::stoi(mRequest.post("contact-gender"));
                            student.contact.update();
                        }
                        else
                        {
                            student.contact = mModel.getContactById(mRequest.post("contact"));
                        }

                        student.update();

                        std::cout << redirect(mUrl.get("admin-student"));
                        mSession.set("flash_success", "L'élève " + student.personDetail.firstName + " " + student.personDetail.name + " a bien été édité");

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

        std::string AdminStudentController::deleteStudent()
        {
            entity::Student student = mModel.getStudentById(mRequest.get()["id"]);

            if(student.validEntity == true)
            {
                student.destroy();
                mSession.set("flash_success", "L'élève " + student.personDetail.firstName + " " + student.personDetail.name + " a bien été supprimé");
            }

            return redirect404();
        }

        std::string AdminStudentController::seeStudent()
        {
            entity::Student student = mModel.getStudentById(mRequest.get()["id"]);

            if(student.validEntity == true)
            {
                core::Template tpl("adminStudent/seeStudent", "seeStudent", mConfig, mRequest);
                tpl.var("title", student.personDetail.firstName + " - " + student.personDetail.name);
                tpl.var("filAriane", "Élèves/" + student.personDetail.firstName + " - " + student.personDetail.name);
                tpl.var("student", student);

                return tpl.render();
            }

            return "status:404";
        }

        std::string AdminStudentController::reportGenerateStudent()
        {
            entity::Student student = mModel.getStudentById(mRequest.get()["id"]);

            if(student.validEntity == true)
            {
                //on verifie qu'il y a bien assez de notes pas rapport aux nombres de notes pas cours qu'il suit
                if(mModel.checkMarkEnough(student))
                {
                    core::Sql sql(mDatabase);
                    sql.var("student", student.id);
                    sql.query("DELETE FROM report_card WHERE student_id = :student");
                    sql.execute();

                    entity::ReportCard report(mDatabase);
                    report.student = student;
                    report.save();

                    std::cout << redirect(mUrl.get("admin-student"));
                    mSession.set("flash_success", "Carnet de notes généré");
                }
                else
                {
                    std::cout << redirect(mUrl.get("admin-student"));
                    mSession.set("flash_success", "Certaines notes n'ont pas encore été renseignées");
                }

                return "";
            }

            return "status:404";
        }
    }

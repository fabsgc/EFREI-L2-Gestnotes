/*\
 | ------------------------------------------------------
 | @file : UserController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur utilisateur
 | ------------------------------------------------------
\*/

#include "UserController.hpp"

    namespace app
    {
        UserController::UserController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string UserController::home()
        {
            entity::Admin admin(mDatabase);
            entity::Teacher teacher(mDatabase);
            entity::Student student(mDatabase);
            std::string userType = detectUserType(mSession.get("id"));

            core::Template tpl("user/home", "home", mConfig, mRequest);
            tpl.var("title", "Profil");
            tpl.var("filAriane", "Profil");

            core::FormValidator form(mRequest, mDatabase);
            form.add("email", "email", core::form::Type::input, core::form::Contraint::email, "", "vous devez donner un email valide");
            form.add("address", "adresse", core::form::Type::input, core::form::Contraint::different, "", "vous devez donner votre adresse");
            form.add("postalCode", "code postal", core::form::Type::input, core::form::Contraint::match, "[a-zA-Z0-9]+", "vous devez donner un code postal valide");
            form.add("country", "pays", core::form::Type::input, core::form::Contraint::different, "", "vous devez indiquer votre pays");
            form.add("city", "ville", core::form::Type::input, core::form::Contraint::different, "", "vous devez indiquer votre ville");
            form.add("password", "mot de passe", core::form::Type::input, core::form::Contraint::sizeMin, "6", "votre mot de passe doit faire au moins 6 caractères");
            form.add("phone-mobile", "téléphone mobile", core::form::Type::input, core::form::Contraint::match, "^0[1-78][0-9]{8}$", "veuillez saisir un numéro de téléphone valide");
            form.add("phone-home", "téléphone fixe", core::form::Type::input, core::form::Contraint::match, "^0[1-78][0-9]{8}$", "veuillez saisir un numéro de téléphone valide");
            form.add("token", "sécurité", core::form::Type::input, core::form::Contraint::equalTo, mSession.get("token"), mConfig.getDefine()["form-crsf"]);

            if(userType == USER_ADMIN)
            {
                admin = mModel.getAdminById(mSession.get("id"));
                form.add("email", "email", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM person_detail WHERE email = :input AND id != " + var2Str(admin.personDetail.id) + "][==][0]", "quelqu'un utilise déjà cette adresse email");
                tpl.var("user", admin);
            }
            else if(userType == USER_TEACHER)
            {
                teacher = mModel.getTeacherById(mSession.get("id"));
                form.add("email", "email", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM person_detail WHERE email = :input AND id != " + var2Str(teacher.personDetail.id) + "][==][0]", "quelqu'un utilise déjà cette adresse email");
                tpl.var("user", teacher);
            }
            else if(userType == USER_STUDENT)
            {
                student = mModel.getStudentById(mSession.get("id"));
                form.add("email", "email", core::form::Type::input, core::form::Contraint::sql, "[SELECT id FROM person_detail WHERE email = :input AND id != " + var2Str(student.personDetail.id) + "][==][0]", "quelqu'un utilise déjà cette adresse email");
                tpl.var("user", student);
            }

            if(form.sent())
            {
                if(form.check())
                {
                    if(userType == USER_ADMIN)
                    {
                        admin.personDetail.email = mRequest.post()["email"];
                        admin.personDetail.address = mRequest.post()["address"];
                        admin.personDetail.city = mRequest.post()["city"];
                        admin.personDetail.postalCode = mRequest.post()["postalCode"];
                        admin.personDetail.country = mRequest.post()["country"];
                        admin.personDetail.phoneHome = mRequest.post()["phone-home"];
                        admin.personDetail.phoneMobile = mRequest.post()["phone-mobile"];
                        admin.password = getSha1(mRequest.post()["password"]);
                        admin.update();
                    }
                    else if(userType == USER_TEACHER)
                    {
                        teacher.personDetail.email = mRequest.post()["email"];
                        teacher.personDetail.address = mRequest.post()["address"];
                        teacher.personDetail.city = mRequest.post()["city"];
                        teacher.personDetail.postalCode = mRequest.post()["postalCode"];
                        teacher.personDetail.country = mRequest.post()["country"];
                        teacher.personDetail.phoneHome = mRequest.post()["phone-home"];
                        teacher.personDetail.phoneMobile = mRequest.post()["phone-mobile"];
                        teacher.password = getSha1(mRequest.post()["password"]);
                        teacher.update();
                    }
                    else if(userType == USER_STUDENT)
                    {
                        student.personDetail.email = mRequest.post()["email"];
                        student.personDetail.address = mRequest.post()["address"];
                        student.personDetail.city = mRequest.post()["city"];
                        student.personDetail.postalCode = mRequest.post()["postalCode"];
                        student.personDetail.country = mRequest.post()["country"];
                        student.personDetail.phoneHome = mRequest.post()["phone-home"];
                        student.personDetail.phoneMobile = mRequest.post()["phone-mobile"];
                        student.password = getSha1(mRequest.post()["password"]);
                        student.update();
                    }

                    std::cout << redirect(mUrl.get("user-home"));
                    mSession.set("flash_success", "Votre profil a été correctement édité");

                    return "";
                }
                else
                {
                    tpl.var("formErrors", form.getErrors());
                }
            }

            return tpl.render();
        }

        std::string UserController::login()
        {
            if(!isset(mRequest.post(), var2Str("username")))
            {
                core::Template tpl("user/login", "login", mConfig, mRequest);
                tpl.var("title", "Connexion");

                return tpl.render();
            }
            else
            {
                if(mRequest.post()["username"] != "" && mRequest.post()["password"] != "")
                {
                    std::string userType = detectUserType(mRequest.post()["username"]);
                    dataMap data = mModel.getUserById(mRequest.post()["username"], mRequest.post()["password"], userType);

                    if(data.size() == 1)
                    {
                        mSession.set("id", data["0"]["uid"]);
                        mSession.set("name", data["0"]["name"]);
                        mSession.set("firstname", data["0"]["firstname"]);
                        mSession.set("logged", "1");
                        mSession.set("role", userType);
                        mSession.set("avatar", data["0"]["avatar"]);
                        mSession.set("email", data["0"]["email"]);
                        mSession.set("token", getSha1(genRandom(30)));

                        return "1";
                    }
                }
            }

            return "0";
        }

        std::string UserController::logout()
        {
            if(mSession.exist("id"))
            {
                mSession.removeAll();
            }

            return "";
        }
    }

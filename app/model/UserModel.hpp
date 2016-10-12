/*\
 | ------------------------------------------------------
 | @file : UserModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des utilisateurs
 | ------------------------------------------------------
\*/

#ifndef USERMODEL_HPP_INCLUDED
#define USERMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class UserModel : core::Model
        {
            public :
                UserModel(core::Config &config, core::Database &database, core::Request &request);
                dataMap getUserById(std::string id, std::string password, std::string type);
                entity::Student getStudentById(std::string id);
                entity::Teacher getTeacherById(std::string id);
                entity::Admin getAdminById(std::string id);
        };
    }

#endif // USERMODEL_HPP_INCLUDED

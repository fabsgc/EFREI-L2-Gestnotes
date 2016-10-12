/*\
 | ------------------------------------------------------
 | @file : AdminGroupModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des groupes par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINGROUPMODEL_HPP_INCLUDED
#define ADMINGROUPMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class AdminGroupModel : core::Model
        {
            public :
                AdminGroupModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Group getGroupById(std::string id);
                std::vector<entity::Group> getGroups();
                std::vector<entity::Student> getStudentsByGroup(std::string id);
                std::vector<entity::Student> getStudentsNotInGroup();
                std::vector<entity::Student> getStudentsNotInGroupAndThisGroup(std::string id);
                std::vector<entity::Student> getStudentsThisGroup(std::string id);
        };
    }

#endif // ADMINGROUPMODEL_HPP_INCLUDED

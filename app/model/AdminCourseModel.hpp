/*\
 | ------------------------------------------------------
 | @file : AdminCourseModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des cours par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINCOURSEMODEL_HPP_INCLUDED
#define ADMINCOURSEMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class AdminCourseModel : core::Model
        {
            public :
                AdminCourseModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Course getCourseById(std::string id);
                entity::Teacher getTeacherById(std::string id);
                std::vector<entity::Group> getGroups();
                std::vector<entity::Course> getCourses();
                std::vector<entity::Teacher> getTeachers();
        };
    }

#endif // ADMINCOURSEMODEL_HPP_INCLUDED

/*\
 | ------------------------------------------------------
 | @file : AdminTeacherModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des professeurs par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINTEACHERMODEL_HPP_INCLUDED
#define ADMINTEACHERMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class AdminTeacherModel : core::Model
        {
            public :
                AdminTeacherModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Teacher getTeacherById(std::string id);
                std::vector<entity::Student> getStudentsTeacher(std::string id);
                std::vector<entity::Course> getCoursesTeacher(std::string id);
                std::vector<entity::Teacher> getTeachers();
                int getLastTeacherId();
        };
    }

#endif // ADMINTEACHERMODEL_HPP_INCLUDED

/*\
 | ------------------------------------------------------
 | @file : TeacherCourseModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des cours par les professeurs
 | ------------------------------------------------------
\*/

#ifndef TEACHERCOURSEMODEL_HPP_INCLUDED
#define TEACHERCOURSEMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class TeacherCourseModel : core::Model
        {
            public :
                TeacherCourseModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Teacher getTeacherById(std::string id);
                std::vector<entity::Course> getCoursesByTeacherPrincipal(entity::Teacher teacher);
                std::vector<entity::Course> getCoursesByTeacherAssistant(entity::Teacher teacher);
        };
    }

#endif // TEACHERCOURSEMODEL_HPP_INCLUDED

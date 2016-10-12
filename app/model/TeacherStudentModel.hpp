/*\
 | ------------------------------------------------------
 | @file : TeacherStudentModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des élèves par les professeurs
 | ------------------------------------------------------
\*/

#ifndef TEACHERSTUDENTMODEL_HPP_INCLUDED
#define TEACHERSTUDENTMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class TeacherStudentModel : core::Model
        {
            public :
                TeacherStudentModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Teacher getTeacherById(std::string id);
                std::vector<entity::Student> getStudentsByTeacher(std::string teacher);
                std::vector<entity::Mark> getMarks();
        };
    }

#endif // TEACHERSTUDENTMODEL_HPP_INCLUDED

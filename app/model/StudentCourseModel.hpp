/*\
 | ------------------------------------------------------
 | @file : StudentCourseModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des cours par les élèves
 | ------------------------------------------------------
\*/

#ifndef STUDENTCOURSEMODEL_HPP_INCLUDED
#define STUDENTCOURSEMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class StudentCourseModel : core::Model
        {
            public :
                StudentCourseModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Student getStudentById(std::string id);
                std::vector<entity::Course> getCoursesByStudent(entity::Student student);
        };
    }

#endif // STUDENTCOURSEMODEL_HPP_INCLUDED

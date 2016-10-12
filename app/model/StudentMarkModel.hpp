/*\
 | ------------------------------------------------------
 | @file : StudentMarkModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des notes par les élèves
 | ------------------------------------------------------
\*/

#ifndef STUDENTMARKMODEL_HPP_INCLUDED
#define STUDENTMARKMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class StudentMarkModel : core::Model
        {
            public :
                StudentMarkModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Student getStudentById(std::string id);
                entity::ReportCard getReportByStudent(std::string student);
                std::vector<entity::Mark> getMarksByStudent(std::string student);
                std::vector<entity::Course> getCoursesByStudent(entity::Student student);
        };
    }

#endif // STUDENTMARKMODEL_HPP_INCLUDED

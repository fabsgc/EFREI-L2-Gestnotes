/*\
 | ------------------------------------------------------
 | @file : TeacherMarkModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des notes par les professeurs
 | ------------------------------------------------------
\*/

#ifndef TEACHERMARKMODEL_HPP_INCLUDED
#define TEACHERMARKMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class TeacherMarkModel : core::Model
        {
            public :
                TeacherMarkModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Teacher getTeacherById(std::string id);
                entity::Course getCourseById(std::string id, std::string teacher);
                entity::Group getGroupById(std::string id, std::string teacher);
                entity::Student getStudentById(std::string id);
                std::vector<entity::Group> getGroups(std::string teacher);
                std::vector<entity::Student> getStudentsByGroupAndCourse(std::string group, std::string course);
                std::vector<entity::Course> getCoursesByGroup(std::string group, std::string teacher);
                std::vector<entity::Mark>  getMarksByCourse(std::string course);
                bool checkGroupCourse(std::string course, std::string group);
                bool markEnabled(entity::Course course);
                bool checkMarkExist(std::string course, std::string student, std::string type);
                entity::Mark getMarkExist(std::string course, std::string student, std::string type);
                std::vector<entity::ReportCard> getReports();
        };
    }

#endif // TEACHERMARKMODEL_HPP_INCLUDED

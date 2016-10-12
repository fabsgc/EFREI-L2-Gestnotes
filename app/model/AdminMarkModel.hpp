/*\
 | ------------------------------------------------------
 | @file : AdminMarkModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des notes par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINMARKMODEL_HPP_INCLUDED
#define ADMINMARKMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class AdminMarkModel : core::Model
        {
            public :
                AdminMarkModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Course getCourseById(std::string id);
                entity::Group getGroupById(std::string id);
                entity::Student getStudentById(std::string id);
                std::vector<entity::Group> getGroups();
                std::vector<entity::Student> getStudentsByGroupAndCourse(std::string group, std::string course);
                std::vector<entity::Course> getCoursesByGroup(std::string group);
                std::vector<entity::Mark>  getMarksByCourse(std::string course);
                bool checkGroupCourse(std::string course, std::string group);
                bool markEnabled(entity::Course course);
                bool checkMarkExist(std::string course, std::string student, std::string type);
                entity::Mark getMarkExist(std::string course, std::string student, std::string type);
        };
    }

#endif // ADMINMARKMODEL_HPP_INCLUDED

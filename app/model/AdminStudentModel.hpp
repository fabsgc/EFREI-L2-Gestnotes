/*\
 | ------------------------------------------------------
 | @file : AdminStudentModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des élèves par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINSTUDENTMODEL_HPP_INCLUDED
#define ADMINSTUDENTMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class AdminStudentModel : core::Model
        {
            public :
                AdminStudentModel(core::Config &config, core::Database &database, core::Request &request);
                entity::Student getStudentById(std::string id);
                entity::Contact getContactById(std::string id);
                entity::Teacher getTeacherById(std::string id);
                entity::Group getGroupById(std::string id);
                std::vector<entity::Course> getCoursesByGroup(std::string id);
                std::vector<entity::Contact> getContacts();
                std::vector<entity::Teacher> getTeachers();
                std::vector<entity::Student> getStudents(std::string search = "");
                bool checkMarkEnough(entity::Student student);
                int getLastUserId();
                bool checkMarkByStudentByCourseByType(entity::Student student, entity::Course course, std::string type);
        };
    }

#endif // ADMINSTUDENTMODEL_HPP_INCLUDED

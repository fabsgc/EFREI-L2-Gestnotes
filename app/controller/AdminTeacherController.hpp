/*\
 | ------------------------------------------------------
 | @file : AdminTeacherController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des professeurs par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINTEACHERCONTROLLER_HPP_INCLUDED
#define ADMINTEACHERCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/AdminTeacherModel.hpp"

    namespace app
    {
        class AdminTeacherController : public core::Controller
        {
            public :
                AdminTeacherController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();
                std::string newTeacher();
                std::string editTeacher();
                std::string deleteTeacher();
                std::string seeTeacher();

            private :
                AdminTeacherModel mModel;
        };
    }

#endif // ADMINTEACHERCONTROLLER_HPP_INCLUDED

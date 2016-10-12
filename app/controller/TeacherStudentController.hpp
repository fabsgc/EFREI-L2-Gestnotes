/*\
 | ------------------------------------------------------
 | @file : TeacherStudentController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des élèves par les professeurs
 | ------------------------------------------------------
\*/

#ifndef TEACHERSTUDENTCONTROLLER_HPP_INCLUDED
#define TEACHERSTUDENTCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/TeacherStudentModel.hpp"

    namespace app
    {
        class TeacherStudentController : public core::Controller
        {
            public :
                TeacherStudentController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();

            private :
                TeacherStudentModel mModel;
        };
    }

#endif // TEACHERSTUDENTCONTROLLER_HPP_INCLUDED

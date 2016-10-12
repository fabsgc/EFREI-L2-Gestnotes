/*\
 | ------------------------------------------------------
 | @file : AdminStudentController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des élèves par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINSTUDENTCONTROLLER_HPP_INCLUDED
#define ADMINSTUDENTCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/AdminStudentModel.hpp"

    namespace app
    {
        class AdminStudentController : public core::Controller
        {
            public :
                AdminStudentController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();
                std::string newStudent();
                std::string editStudent();
                std::string deleteStudent();
                std::string seeStudent();
                std::string reportGenerateStudent();

            private :
                AdminStudentModel mModel;
        };
    }

#endif // ADMINSTUDENTCONTROLLER_HPP_INCLUDED

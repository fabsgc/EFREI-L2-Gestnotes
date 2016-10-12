/*\
 | ------------------------------------------------------
 | @file : TeacherStudentController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des notes par les professeurs
 | ------------------------------------------------------
\*/

#ifndef TEACHERMARKCONTROLLER_HPP_INCLUDED
#define TEACHERMARKCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/TeacherMarkModel.hpp"

    namespace app
    {
        class TeacherMarkController : public core::Controller
        {
            public :
                TeacherMarkController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();
                std::string group();
                std::string course();
                std::string setMark();

            private :
                TeacherMarkModel mModel;
        };
    }

#endif // TEACHERMARKCONTROLLER_HPP_INCLUDED

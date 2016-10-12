/*\
 | ------------------------------------------------------
 | @file : TeacherCourseController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des cours par les professeurs
 | ------------------------------------------------------
\*/

#ifndef TEACHERCOURSECONTROLLER_HPP_INCLUDED
#define TEACHERCOURSECONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/TeacherCourseModel.hpp"

    namespace app
    {
        class TeacherCourseController : public core::Controller
        {
            public :
                TeacherCourseController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();

            private :
                TeacherCourseModel mModel;
        };
    }

#endif // TEACHERCOURSECONTROLLER_HPP_INCLUDED

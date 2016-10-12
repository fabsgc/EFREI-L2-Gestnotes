/*\
 | ------------------------------------------------------
 | @file : AdminCourseController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des cours par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINCOURSECONTROLLER_HPP_INCLUDED
#define ADMINCOURSECONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/AdminCourseModel.hpp"

    namespace app
    {
        class AdminCourseController : public core::Controller
        {
            public :
                AdminCourseController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();
                std::string newCourse();
                std::string editCourse();
                std::string deleteCourse();

            private :
                AdminCourseModel mModel;
        };
    }

#endif // ADMINCOURSECONTROLLER_HPP_INCLUDED

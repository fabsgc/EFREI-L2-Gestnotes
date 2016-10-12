/*\
 | ------------------------------------------------------
 | @file : StudentMarkController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des cours par les élèves
 | ------------------------------------------------------
\*/

#ifndef STUDENTCOURSECONTROLLER_HPP_INCLUDED
#define STUDENTCOURSECONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/StudentCourseModel.hpp"

    namespace app
    {
        class StudentCourseController : public core::Controller
        {
            public :
                StudentCourseController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();

            private :
                StudentCourseModel mModel;
        };
    }

#endif // STUDENTCOURSECONTROLLER_HPP_INCLUDED

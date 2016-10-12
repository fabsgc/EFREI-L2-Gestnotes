/*\
 | ------------------------------------------------------
 | @file : StudentMarkController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des notes par les élèves
 | ------------------------------------------------------
\*/

#ifndef STUDENTMARKCONTROLLER_HPP_INCLUDED
#define STUDENTMARKCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/StudentMarkModel.hpp"

    namespace app
    {
        class StudentMarkController : public core::Controller
        {
            public :
                StudentMarkController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();
                std::string report();

            private :
                StudentMarkModel mModel;
        };
    }

#endif // STUDENTMARKCONTROLLER_HPP_INCLUDED

/*\
 | ------------------------------------------------------
 | @file : AdminMarkController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des notes par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINMARKCONTROLLER_HPP_INCLUDED
#define ADMINMARKCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/AdminMarkModel.hpp"

    namespace app
    {
        class AdminMarkController : public core::Controller
        {
            public :
                AdminMarkController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();
                std::string group();
                std::string course();
                std::string setMark();

            private :
                AdminMarkModel mModel;
        };
    }

#endif // ADMINMARKCONTROLLER_HPP_INCLUDED

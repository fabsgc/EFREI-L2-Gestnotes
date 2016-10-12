/*\
 | ------------------------------------------------------
 | @file : AdminGroupController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des groupes par les administrateurs
 | ------------------------------------------------------
\*/

#ifndef ADMINGROUPCONTROLLER_HPP_INCLUDED
#define ADMINGROUPCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/AdminGroupModel.hpp"

    namespace app
    {
        class AdminGroupController : public core::Controller
        {
            public :
                AdminGroupController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();
                std::string newGroup();
                std::string editGroup();
                std::string deleteGroup();
                std::string seeGroup();

            private :
                AdminGroupModel mModel;
        };
    }

#endif // ADMINGROUPCONTROLLER_HPP_INCLUDED

/*\
 | ------------------------------------------------------
 | @file : UserController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur utilisateur
 | ------------------------------------------------------
\*/

#ifndef USERCONTROLLER_HPP_INCLUDED
#define USERCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/UserModel.hpp"

    namespace app
    {
        class UserController : public core::Controller
        {
            public :
                UserController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();
                std::string login();
                std::string logout();

            private :
                UserModel mModel;
        };
    }

#endif // USERCONTROLLER_HPP_INCLUDED

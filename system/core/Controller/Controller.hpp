/*\
 | ------------------------------------------------------
 | @file : Controller.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe abstraite représentant un contrôleur dans l'architecture MVC
 | ------------------------------------------------------
\*/

#ifndef CONTROLLER_HPP_INCLUDED
#define CONTROLLER_HPP_INCLUDED

#include "../../include.hpp"

    namespace core
    {
        class Controller
        {
            public :
                              Controller(core::Config &config, core::Database &database, core::Request &request);
                virtual       ~Controller() = 0;
                virtual void  init();

            protected :
                Config&       mConfig;
                Database&     mDatabase;
                Request&      mRequest;
                Url           mUrl;
                Session mSession;
        };
    }

#endif // CONTROLLER_HPP_INCLUDED

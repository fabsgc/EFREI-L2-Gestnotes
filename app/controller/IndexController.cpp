/*\
 | ------------------------------------------------------
 | @file : IndexController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion de la page d'accueil
 | ------------------------------------------------------
\*/

#include "IndexController.hpp"

    namespace app
    {
        IndexController::IndexController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string IndexController::home()
        {
            core::Template tpl("index/home", "home", mConfig, mRequest);
            tpl.var("title", "Accueil");
            return tpl.render();
        }
    }

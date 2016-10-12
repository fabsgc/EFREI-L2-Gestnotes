/*\
 | ------------------------------------------------------
 | @file : Controller.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe abstraite représentant un contrôleur dans l'architecture MVC
 | ------------------------------------------------------
\*/

#include "Controller.hpp"

    namespace core
    {
        Controller::Controller(core::Config &config, core::Database &database, core::Request &request) :
        mConfig(config),
        mDatabase(database),
        mRequest(request),
        mUrl(config)
        {
            mSession.setCookie(request.cookie());
        }

        void Controller::init()
        {

        }

        Controller::~Controller()
        {

        }
    }

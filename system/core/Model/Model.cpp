/*\
 | ------------------------------------------------------
 | @file : Model.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe abstraite représentant le modèle dans l'architecture MVC
 | ------------------------------------------------------
\*/

#include "Model.hpp"

    namespace core
    {
        Model::Model(core::Config &config, core::Database &database, core::Request &request) :
        mConfig(config),
        mDatabase(database),
        mRequest(request)
        {
            mSession.setCookie(request.cookie());
        }

        Model::~Model()
        {

        }
    }

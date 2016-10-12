/*\
 | ------------------------------------------------------
 | @file : IndexMode.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion de la page d'accueil
 | ------------------------------------------------------
\*/

#include "IndexModel.hpp"

    namespace app
    {
        IndexModel::IndexModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }
    }

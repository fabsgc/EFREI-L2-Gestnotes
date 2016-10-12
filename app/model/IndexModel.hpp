/*\
 | ------------------------------------------------------
 | @file : IndexModel.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion de la page d'accueil
 | ------------------------------------------------------
\*/

#ifndef INDEXMODEL_HPP_INCLUDED
#define INDEXMODEL_HPP_INCLUDED

#include "../include.hpp"

    namespace app
    {
        class IndexModel : core::Model
        {
            public :
                IndexModel(core::Config &config, core::Database &database, core::Request &request);
        };
    }

#endif // INDEXMODEL_HPP_INCLUDED

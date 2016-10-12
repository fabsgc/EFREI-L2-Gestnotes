/*\
 | ------------------------------------------------------
 | @file : Model.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe abstraite représentant le modèle dans l'architecture MVC
 | ------------------------------------------------------
\*/

#ifndef MODEL_HPP_INCLUDED
#define MODEL_HPP_INCLUDED

#include "../../include.hpp"

    namespace core
    {
        class Model
        {
            public :
                          Model(core::Config &config, core::Database &database, core::Request &request);
                virtual   ~Model() = 0;

            protected :
                Config&   mConfig;
                Database& mDatabase;
                Session   mSession;
                Request&  mRequest;
        };
    }

#endif // MODEL_HPP_INCLUDED

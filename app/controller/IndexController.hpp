/*\
 | ------------------------------------------------------
 | @file : IndexController.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion de la page d'accueil
 | ------------------------------------------------------
\*/

#ifndef INDEXCONTROLLER_HPP_INCLUDED
#define INDEXCONTROLLER_HPP_INCLUDED

#include "../include.hpp"
#include "../model/IndexModel.hpp"

    namespace app
    {
        class IndexController : public core::Controller
        {
            public :
                IndexController(core::Config &config, core::Database &database, core::Request &request);
                std::string home();

            private :
                IndexModel mModel;
        };
    }

#endif // INDEXCONTROLLER_HPP_INCLUDED

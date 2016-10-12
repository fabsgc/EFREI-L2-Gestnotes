/*\
 | ------------------------------------------------------
 | @file : Auth.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Class gérant les droits d'accès pour une page (se base sur les données de l'objet Request)
 | ------------------------------------------------------
\*/

#ifndef AUTH_HPP_INCLUDED
#define AUTH_HPP_INCLUDED

#include <iostream>
#include "../Session/Session.hpp"
#include "../Request/Request.hpp"
#include "../Config/Config.hpp"
#include "../Routing/Route.hpp"
#include "../Url/Url.hpp"

    namespace core
    {
        class Auth
        {
            public :
                        Auth();
                        ~Auth();
                void    setCookie(stringMap cookie);
                bool    check(Route route, Config& config, Request& request);

            private :
                Session mSession;
        };
    }

#endif // AUTH_HPP_INCLUDED

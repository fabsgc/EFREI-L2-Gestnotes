/*\
 | ------------------------------------------------------
 | @file : Url.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : génération d'url à partir du fichier route.xml
 | ------------------------------------------------------
\*/

#ifndef URL_HPP_INCLUDED
#define URL_HPP_INCLUDED

#include <iostream>
#include <cstdarg>
#include <string>
#include <regex>
#include "../Routing/Route.hpp"
#include "../Config/Config.hpp"

    namespace core
    {
        class Url
        {
            public :
                            Url(Config& config);
                            ~Url();
                std::string get(const char * arg, int number = 0, ...);

            private :
                Config&     mConfig;
        };
    }

#endif // URL_HPP_INCLUDED

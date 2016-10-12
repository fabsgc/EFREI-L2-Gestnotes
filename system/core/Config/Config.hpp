/*\
 | ------------------------------------------------------
 | @file : Config.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe config regroupant toutes les données
 | ------------------------------------------------------
\*/

#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "../Routing/Route.hpp"
#include "../Tinyxml/tinyxml.h"

    const std::string CONFIG_DATABASE =  "conf/database.xml";
    const std::string CONFIG_DEFINE   =  "conf/define.xml";
    const std::string CONFIG_AUTH     =  "conf/auth.xml";
    const std::string CONFIG_ROUTE    =  "conf/route.xml";

    namespace core
    {
        class Config
        {
            public :
                                            Config();
                                            ~Config();
                std::map<std::string,Route> getRoute() const;
                stringMap                   getDefine() const;
                stringMap                   getDatabase() const;
                stringMap                   getAuth() const;

            private :
                void                        setRoute();
                void                        setDefine();
                void                        setDatabase();
                void                        setAuth();

            private :
                std::map<std::string,Route> mRoute;
                stringMap                 mDefine;
                stringMap                 mDatabase;
                stringMap                 mAuth;
        };
    }

#endif // CONFIG_HPP_INCLUDED

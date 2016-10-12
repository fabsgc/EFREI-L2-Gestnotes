/*\
 | ------------------------------------------------------
 | @file : Route.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe représentant dans le programme une ligne du fichier route.xml
 | ------------------------------------------------------
\*/

#ifndef ROUTER_HPP_INCLUDED
#define ROUTER_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "../../../function.hpp"

    namespace core
    {
        class Route
        {
            public :
                                         Route(std::string name, std::string url, std::string controller, std::string action, std::string logged, std::string vars, std::string roles);
                                         ~Route();
                std::string              getName() const;
                std::string              getUrl() const;
                std::string              getController() const;
                std::string              getAction() const;
                std::string              getLogged() const;
                std::vector<std::string> getVars() const;
                std::vector<std::string> getRoles() const;
                stringMap                getAll() const;
                bool                     match(std::string url) const;

            private :
                std::string              mName;
                std::string              mUrl;
                std::string              mController;
                std::string              mAction;
                std::string              mLogged;
                std::vector<std::string> mVars;
                std::vector<std::string> mRoles;
        };
    }

#endif // ROUTER_HPP_INCLUDED

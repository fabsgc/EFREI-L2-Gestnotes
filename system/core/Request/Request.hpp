/*\
 | ------------------------------------------------------
 | @file : Request.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe représentant une requête faite par l'utilisateur (variables post et get, method, cookie, route etc.)
 | ------------------------------------------------------
\*/

#ifndef REQUEST_HPP_INCLUDED
#define REQUEST_HPP_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include "../Routing/Route.hpp"

    namespace core
    {
        class Request
        {
            public :
                            Request();
                            ~Request();
                void        init(const stringMap& routeVar);
                std::string get(std::string key);
                std::string post(std::string key);
                std::string cookie(std::string key);
                std::string getMethod();
                stringMap   get() const;
                stringMap   post() const;
                stringMap   cookie() const;
                void        setRoute(const Route& route);
                Route       getRoute() const;

            private :
                std::string urlDecode(std::string str);
                void        initGet(const stringMap& routeVar);
                void        initPost();
                void        initCookie();

            private :
                stringMap   mGet;
                stringMap   mPost;
                stringMap   mCookie;
                std::string mMethod;
                Route       mRoute;
        };
    }

#endif // REQUEST_HPP_INCLUDED

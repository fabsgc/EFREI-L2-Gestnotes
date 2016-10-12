/*\
 | ------------------------------------------------------
 | @file : Session.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe permettant de gérer le système de sessions du framework
 | ------------------------------------------------------
\*/

#ifndef SESSION_HPP_INCLUDED
#define SESSION_HPP_INCLUDED

#include "../../../function.hpp"

    const std::string SESSION_FILE     = "app/session/session_";
    const std::string SESSION_PATH     = "app/session/";

    namespace core
    {
        class Session
        {
            public :
                Session();
                ~Session();
                void        setCookie(stringMap cookie);
                std::string get(std::string name);
                void        set(std::string name, std::string value);
                void        remove(std::string name);
                bool        exist(std::string name);
                stringMap all();
                bool        removeAll();
                bool        removeFlash();

            private :
                stringMap mCookie;
        };
    }

#endif // SESSION_HPP_INCLUDED

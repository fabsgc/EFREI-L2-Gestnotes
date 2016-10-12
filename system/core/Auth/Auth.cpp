/*\
 | ------------------------------------------------------
 | @file : Auth.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Class gérant les droits d'accès pour une page (se base sur les données de l'objet Request)
 | ------------------------------------------------------
\*/

#include "Auth.hpp"

    namespace core
    {
        Auth::Auth()
        {

        }

        void Auth::setCookie(stringMap cookie)
        {
            mSession.setCookie(cookie);
        }

        bool Auth::check(Route route, Config& config, Request& request)
        {
            Url url(config);

            if(request.cookie("sessionid") == "")
            {
                std::cout << redirect(url.get("home"));
                return true;
            }

            if(route.getLogged() == "*")
            {
                return true;
            }
            else if(route.getLogged() == "1")
            {
                //on vérifie que la personne est bien connectée
                if(mSession.exist(config.getAuth()["logged"]))
                {
                    std::string logged = mSession.get(config.getAuth()["logged"]);
                    std::string role = mSession.get(config.getAuth()["role"]);
                    std::string crsf = config.getAuth()["crsf"];
                    std::vector<std::string> roles = route.getRoles();

                    //on vérifie la faille CRSF
                    if(request.post()[crsf] != "")
                    {
                        if(request.post()[crsf] != mSession.get(crsf))
                            return false;
                    }

                    if(request.get()[crsf] != "")
                    {
                        if(request.get()[crsf] != mSession.get(crsf))
                            return false;
                    }

                    if(std::find(std::begin(roles), std::end(roles), "*") != roles.end())
                    {
                        return true;
                    }
                    else if(std::find(std::begin(roles), std::end(roles), role) != roles.end())
                    {
                        return true;
                    }
                    else
                    {
                        std::cout << redirect(url.get(config.getAuth()["home"].c_str()));
                        return true;
                    }
                }
                else
                {
                    std::cout << redirect(url.get(config.getAuth()["login"].c_str()));
                    return true;
                }
            }
            else
            {
                if(!mSession.exist(config.getAuth()["logged"]))
                {
                    return true;
                }
                else
                {
                    std::cout << redirect(url.get("home"));
                    return true;
                }
            }

            return false;
        }

        Auth::~Auth()
        {

        }
    }

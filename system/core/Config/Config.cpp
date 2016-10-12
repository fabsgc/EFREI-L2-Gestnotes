/*\
 | ------------------------------------------------------
 | @file : Config.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe config regroupant toutes les données
 | ------------------------------------------------------
\*/

#include "Config.hpp"

    namespace core
    {
        Config::Config()
        {
            setRoute();
            setDefine();
            setDatabase();
            setAuth();
        }

        Config::~Config()
        {

        }

        void Config::setRoute()
        {
            TiXmlDocument doc(CONFIG_ROUTE.c_str());

            if(doc.LoadFile())
            {
                TiXmlHandle hdl(&doc);
                TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

                if(elem)
                {
                    while(elem)
                    {
                        std::string name        = elem->Attribute("name");
                        std::string url         = elem->Attribute("url");
                        std::string controller  = elem->Attribute("controller");
                        std::string action      = elem->Attribute("action");
                        std::string logged      = elem->Attribute("logged");
                        std::string vars        = elem->Attribute("vars");
                        std::string roles       = elem->Attribute("roles");

                        Route route(name, url, controller, action, logged, vars, roles);
                        mRoute.emplace(name, route);

                        elem = elem->NextSiblingElement();
                    }
                }
            }

        }

        void Config::setDefine()
        {
            TiXmlDocument doc(CONFIG_DEFINE.c_str());

            if(doc.LoadFile())
            {
                TiXmlHandle hdl(&doc);
                TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

                if(elem)
                {
                    while(elem)
                    {
                        std::string name  = elem->Attribute("name");
                        std::string value = elem->Attribute("value");

                        mDefine.emplace(name, value);

                        elem = elem->NextSiblingElement();
                    }
                }
            }
        }

        void Config::setDatabase()
        {
            TiXmlDocument doc(CONFIG_DATABASE.c_str());

            if(doc.LoadFile())
            {
                TiXmlHandle hdl(&doc);
                TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

                if(elem)
                {
                    std::string host     = elem->Attribute("host");
                    std::string user     = elem->Attribute("user");
                    std::string password = elem->Attribute("password");
                    std::string database = elem->Attribute("database");

                    mDatabase.emplace("host", host);
                    mDatabase.emplace("user", user);
                    mDatabase.emplace("password", password);
                    mDatabase.emplace("database", database);
                }
            }
        }

        void Config::setAuth()
        {
            TiXmlDocument doc(CONFIG_AUTH.c_str());

            if(doc.LoadFile())
            {
                TiXmlHandle hdl(&doc);
                TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

                if(elem)
                {
                    std::string login   = elem->Attribute("login");
                    std::string home    = elem->Attribute("home");
                    std::string logged  = elem->Attribute("logged");
                    std::string role    = elem->Attribute("role");
                    std::string crsf    = elem->Attribute("crsf");

                    mAuth.emplace("login", login);
                    mAuth.emplace("home", home);
                    mAuth.emplace("logged", logged);
                    mAuth.emplace("role", role);
                    mAuth.emplace("crsf", crsf);
                }
            }
        }

        std::map<std::string,Route> Config::getRoute() const
        {
            return mRoute;
        }

        stringMap Config::getDefine() const
        {
            return mDefine;
        }

        stringMap Config::getDatabase() const
        {
            return mDatabase;
        }

        stringMap Config::getAuth() const
        {
            return mAuth;
        }

    }

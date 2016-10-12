/*\
 | ------------------------------------------------------
 | @file : Route.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe représentant dans le programme une ligne du fichier route.xml
 | ------------------------------------------------------
\*/

#include "Route.hpp"

    namespace core
    {
        Route::Route(std::string name, std::string url, std::string controller, std::string action, std::string logged, std::string vars, std::string roles) :
        mName(name),
        mUrl(url),
        mController(controller),
        mAction(action),
        mLogged(logged)
        {
            mVars = splitString(vars, ",");
            mRoles = splitString(roles, ",");
        }

        std::string Route::getName() const
        {
            return mName;
        }

        std::string Route::getUrl() const
        {
            return mUrl;
        }

        std::string Route::getController() const
        {
            return mController;
        }

        std::string Route::getAction() const
        {
            return mAction;
        }

        std::string Route::getLogged() const
        {
            return mLogged;
        }

        std::vector<std::string> Route::getVars() const
        {
            return mVars;
        }

        std::vector<std::string> Route::getRoles() const
        {
            return mRoles;
        }

        bool Route::match(std::string url) const
        {
            std::regex reg (mUrl);

            if (std::regex_match (url, reg))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        stringMap Route::getAll() const
        {
            stringMap data;

            data["name"] = mName;
            data["url"]  = mUrl;
            data["controller"] = mController;
            data["action"] = mAction;
            data["logged"] = mLogged;

            return data;
        }

        Route::~Route()
        {

        }
    }

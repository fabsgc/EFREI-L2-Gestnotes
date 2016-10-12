/*\
 | ------------------------------------------------------
 | @file : Session.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe permettant de gérer le système de sessions du framework
 | ------------------------------------------------------
\*/

#include "Session.hpp"

    namespace core
    {
        Session::Session()
        {
        }

        void Session::setCookie(stringMap cookie)
        {
            mCookie = cookie;
        }

        std::string Session::get(std::string name)
        {
            std::string data;

            if(isset(mCookie, var2Str("sessionid")))
            {
                data =  fileGetContent(SESSION_FILE + mCookie["sessionid"] + "_" + name);
            }
            else
            {
                data = fileGetContent(SESSION_FILE + "_" + name);
            }

            return data.substr(0, data.size()-1);
        }

        void Session::set(std::string name, std::string value)
        {
            if(isset(mCookie, var2Str("sessionid")))
            {
                filePutContent(SESSION_FILE +  mCookie["sessionid"] + "_" + name, value);
            }
            else
            {
                filePutContent(SESSION_FILE + "_" + name, value);
            }
        }

        void Session::remove(std::string name)
        {
            if(isset(mCookie, var2Str("sessionid")))
            {
                std::string path = SESSION_FILE + mCookie["sessionid"] + "_" + name.c_str();
                std::remove(path.c_str());
            }
        }

        bool Session::exist(std::string name)
        {
            if(isset(mCookie, var2Str("sessionid")))
            {
                return fileExist(SESSION_FILE + mCookie["sessionid"] + "_" + name);
            }

            return false;
        }

        stringMap Session::all()
        {
            stringMap result;

            DIR *dp;
            struct dirent *dirp;

            if((dp  = opendir(SESSION_PATH.c_str())) == NULL) {
                return result;
            }

            while ((dirp = readdir(dp)) != NULL) {
                std::string name = var2Str(dirp->d_name);
                std::string fileContent = "";
                std::regex regReplace("^(.*)(session_" + mCookie["sessionid"] + "_)(.+)$");

                if(std::regex_match (name, regReplace))
                {
                    fileContent = fileGetContent(SESSION_PATH + var2Str(dirp->d_name));
                    name = std::regex_replace (name, regReplace, "$3");
                    result[name] = fileContent.substr(0, fileContent.size()-1);
                }
            }

            closedir(dp);

            return result;
        }

        bool Session::removeAll()
        {
            DIR *dp;
            struct dirent *dirp;

            if((dp  = opendir(SESSION_PATH.c_str())) == NULL) {
                return false;
            }

            while ((dirp = readdir(dp)) != NULL) {
                std::string name = var2Str(dirp->d_name);
                std::regex regReplace("^(.*)(session_" + mCookie["sessionid"] + "_)(.+)$");

                if(std::regex_match (name, regReplace))
                {
                    std::string path = SESSION_PATH +  name;
                    std::remove(path.c_str());
                }
            }

            closedir(dp);

            return true;
        }

        bool Session::removeFlash()
        {
            DIR *dp;
            struct dirent *dirp;

            if((dp  = opendir(SESSION_PATH.c_str())) == NULL) {
                return false;
            }

            while ((dirp = readdir(dp)) != NULL) {
                std::string name = var2Str(dirp->d_name);
                std::regex regReplace("^(.*)(session_" + mCookie["sessionid"] + "_flash_)(.+)$");

                if(std::regex_match (name, regReplace))
                {
                    std::string path = SESSION_PATH +  name;
                    std::remove(path.c_str());
                }
            }

            closedir(dp);

            return true;
        }

        Session::~Session()
        {

        }
    }

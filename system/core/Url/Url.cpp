/*\
 | ------------------------------------------------------
 | @file : Url.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : génération d'url à partir du fichier route.xml
 | ------------------------------------------------------
\*/

#include "Url.hpp"

    namespace core
    {
        Url::Url(Config& config) :
        mConfig(config)
        {

        }

        std::string Url::get(const char * arg, int number, ...)
        {
            std::map<int,std::string> vars;
            std::string result = "";
            va_list arguments;
            int i = 0;
            std::string name = var2Str(arg);

            va_start(arguments, number);
            while(i < number)
            {
                vars[i] = var2Str(va_arg( arguments, char*));
                i++;
            }
            va_end(arguments);

            if(isset(mConfig.getRoute(), name))
            {
                const std::map<std::string,Route> routes = mConfig.getRoute();
                const Route route = routes.at(name);

                std::regex regVar1 ("(\\([^\\/]+\\))");
                std::string url = std::regex_replace (route.getUrl(), regVar1, "<$1>");
                std::map<int, std::string> urlParts = splitString2(url, "<");
                int j = 0;

                for(auto i = urlParts.begin(); i != urlParts.end(); i++)
                {
                    std::regex regVar2 ("(.*)(\\)>)(.*)");
                    std::regex regVar3 ("\\((.*)\\)>");

                    if(std::regex_match(i->second, regVar2))
                    {
                        if(isset(vars, j))
                        {
                            result += std::regex_replace(i->second, regVar3, vars.at(j));
                        }
                        else
                        {
                            result += std::regex_replace(i->second, regVar3, "");
                        }

                        j++;
                    }
                    else
                    {
                        result += i->second;
                    }

                    result = std::regex_replace(result, std::regex("\\(\\/\\*\\)"), "/");
                }

                return result;
            }

            return "";
        }

        Url::~Url()
        {

        }
    }

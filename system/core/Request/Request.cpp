/*\
 | ------------------------------------------------------
 | @file : Request.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe représentant une requête faite par l'utilisateur (variables post et get, method, cookie, route etc.)
 | ------------------------------------------------------
\*/

#include "Request.hpp"

    namespace core
    {
        Request::Request() :
        mRoute("","","","","","","")
        {
            mMethod = getenv("REQUEST_METHOD");
        }

        void Request::init(const stringMap& routeVar)
        {
            initGet(routeVar);
            initPost();
            initCookie();
        }

        std::string Request::get(std::string key)
        {
            if(mGet.find(key) != mGet.end())
            {
                return mGet.find(key)->second;
            }
            else
            {
                return "";
            }
        }

        std::string Request::post(std::string key)
        {
            if(mPost.find(key) != mPost.end())
            {
                return mPost.find(key)->second;
            }
            else
            {
                return "";
            }
        }

        std::string Request::cookie(std::string key)
        {
            if(mCookie.find(key) != mCookie.end())
            {
                return mCookie.find(key)->second;
            }
            else
            {
                return "";
            }
        }

        stringMap Request::get() const
        {
            return mGet;
        }

        stringMap Request::post() const
        {
            return mPost;
        }

        stringMap Request::cookie() const
        {
            return mCookie;
        }

        std::string Request::urlDecode(std::string str)
        {
            std::string temp;
            register int i;
            char tmp[5], tmpchar;
            strcpy(tmp,"0x");
            int size = str.size();

            for (i=0; i<size; i++)
            {
                if (str[i]=='%')
                {
                    if (i+2<size)
                    {
                        tmp[2] = str[i+1];
                        tmp[3] = str[i+2];
                        tmp[4] = '\0';
                        tmpchar = (char)strtol(tmp,NULL,0);
                        temp+=tmpchar;
                        i += 2;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (str[i]=='+')
                {
                    temp+=' ';
                }
                else
                {
                    temp+=str[i];
                }
            }

            return temp;
        }

        void Request::initGet(const stringMap& routeVar)
        {
            std::string tmpkey, tmpvalue;
            std::string *tmpstr = &tmpkey;
            register char* raw_get = getenv("QUERY_STRING");

            if (raw_get==NULL) {
                mGet.clear();
                return;
            }

            while (*raw_get != '\0')
            {
                if (*raw_get=='&')
                {
                    if (tmpkey!="")
                    {
                        mGet[urlDecode(tmpkey)] = urlDecode(tmpvalue);
                    }

                    tmpkey.clear();
                    tmpvalue.clear();
                    tmpstr = &tmpkey;
                }
                else if (*raw_get=='=')
                {
                    tmpstr = &tmpvalue;
                }
                else
                {
                    (*tmpstr) += (*raw_get);
                }

                raw_get++;
            }

            if (tmpkey!="") {
                mGet[urlDecode(tmpkey)] = urlDecode(tmpvalue);
                tmpkey.clear();
                tmpvalue.clear();
            }

            mGet.insert(routeVar.begin(), routeVar.end());
        }

        void Request::initPost()
        {
            std::string tmpkey, tmpvalue;
            std::string *tmpstr = &tmpkey;
            std::string postData;

            for (std::string line; std::getline(std::cin, line);) {
                postData +=line;
            }

            register char* raw_get = (char*)postData.c_str();

            if (raw_get==NULL) {
                mPost.clear();
                return;
            }

            while (*raw_get != '\0')
            {
                if (*raw_get=='&')
                {
                    if (tmpkey!="")
                    {
                        mPost[urlDecode(tmpkey)] += urlDecode(tmpvalue) + "-";
                    }

                    tmpkey.clear();
                    tmpvalue.clear();
                    tmpstr = &tmpkey;
                }
                else if (*raw_get=='=')
                {
                    tmpstr = &tmpvalue;
                }
                else
                {
                    (*tmpstr) += (*raw_get);
                }

                raw_get++;
            }

            if (tmpkey!="")
            {
                mPost[urlDecode(tmpkey)] = urlDecode(tmpvalue);
                tmpkey.clear();
                tmpvalue.clear();
            }

            std::regex regDeleteComma("^(.*)-$");

            for(auto i = mPost.begin(); i != mPost.end(); i++)
            {
                i->second = std::regex_replace (i->second, regDeleteComma, "$1");
            }
        }

        void Request::initCookie()
        {
            std::string tmpkey, tmpvalue;
            std::string *tmpstr = &tmpkey;
            register char* raw_get = getenv("HTTP_COOKIE");

            if (raw_get==NULL)
            {
                mCookie.clear();
                return;
            }

            while (*raw_get != '\0')
            {
                if (*raw_get=='&')
                {
                    if (tmpkey!="")
                    {
                        mCookie[urlDecode(tmpkey)] = urlDecode(tmpvalue);
                    }

                    tmpkey.clear();
                    tmpvalue.clear();
                    tmpstr = &tmpkey;
                }
                else if (*raw_get=='=')
                {
                    tmpstr = &tmpvalue;
                }
                else
                {
                    (*tmpstr) += (*raw_get);
                }
                raw_get++;
            }

            if (tmpkey!="")
            {
                mCookie[urlDecode(tmpkey)] = urlDecode(tmpvalue);
                tmpkey.clear();
                tmpvalue.clear();
            }
        }

        void Request::setRoute(const Route& route)
        {
            mRoute = route;
        }

        Route Request::getRoute() const
        {
            return mRoute;
        }

        std::string Request::getMethod()
        {
            return mMethod;
        }

        Request::~Request()
        {

        }
    }

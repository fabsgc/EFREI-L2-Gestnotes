/*\
 | ------------------------------------------------------
 | @file : function.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Petite bibliothèque de fonctions souvent utilisées dans l'application
 | ------------------------------------------------------
\*/

#ifndef FUNCTION_HPP_INCLUDED
#define FUNCTION_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <fstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <regex>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sys/types.h>
#include <dirent.h>
#include "system/core/Sha1/Sha1.hpp"

typedef std::map<std::string, std::map<std::string,std::string>> dataMap;
typedef std::map<std::string, std::vector<std::string>>          dataVector;
typedef std::map<std::string, std::string>                       stringMap;
typedef std::vector<std::string>                                 stringVector;

std::vector<std::string>  splitString(std::string input, std::string delimiter);
std::map<int,std::string> splitString2(std::string input, std::string delimiter);
std::string               redirect(std::string url);
std::string               redirect404();
std::string               redirect200();
std::string               escape(std::string const &s);
std::string               htmlSpecialChars(std::string const &s);
std::string               genRandom(const int len);
std::string               replaceBy(std::string input, std::string what, std::string by);
std::string               fileGetContent(std::string path);
std::string               getSha1(std::string str);
bool                      fileExist(std::string path);
void                      filePutContent(std::string path, std::string value);
bool                      str2Bool(std::string x);
bool                      bin2Bool(std::string x);
int                       bool2bin(bool x);

template<typename T>
std::string var2Str(T x)
{
    std::stringstream type;
    type << x;
    return type.str();
}

template<typename T1, typename T2>
bool isset(const std::vector<T1>& x, T2 value)
{
    if(std::find(x.begin(),  x.end(), value) != x.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T1, typename T2, typename T3>
bool isset(const std::map<T1, T2>& x, T3 value)
{
    if(x.find(value) != x.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // FUNCTION_HPP_INCLUDED

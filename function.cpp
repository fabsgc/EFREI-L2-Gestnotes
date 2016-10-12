/*\
 | ------------------------------------------------------
 | @file : function.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Petite bibliothèque de fonctions souvent utilisées dans l'application
 | ------------------------------------------------------
\*/

#include "function.hpp"

std::vector<std::string> splitString(std::string input, std::string delimiter)
{
    std::vector<std::string> output;
    char *pch;
    char *str = strdup(input.c_str());
    pch = strtok (str, delimiter.c_str());

    while (pch != NULL)
    {
        output.push_back(pch);
        pch = strtok (NULL,  delimiter.c_str());
    }

    free(str);

    return output;
}

std::map<int,std::string> splitString2(std::string input, std::string delimiter)
{
    std::map<int,std::string> output;
    char *pch;
    char *str = strdup(input.c_str());
    pch = strtok (str, delimiter.c_str());
    int i = 0;

    while (pch != NULL)
    {
        output[i] = pch;
        pch = strtok (NULL,  delimiter.c_str());
        i++;
    }

    free(str);

    return output;
}

std::string redirect(std::string name)
{
    return "Status: 302 Moved\r\nLocation: " + name + "\r\n\r\n";
}

std::string redirect404()
{
    return "Content-type: text/html;charset=UTF-8\r\nStatus: 404 Not found\r\n\r\n";
}

std::string redirect200()
{
    return "Content-type:text/html;charset=UTF-8\r\n\r\n";
}

bool fileExist(std::string path)
{
    std::ifstream f(path);

    if (f.good())
    {
        f.close();
        return true;
    }
    else
    {
        f.close();
        return false;
    }
}

std::string fileGetContent(std::string path)
{
    std::string output = "", line = "";
    std::ifstream f(path);

    if (f.good())
    {
        while ( getline (f,line) )
        {
            output += line + "\n";
        }
    }

    f.close();

    return output;
}

void filePutContent(std::string path, std::string value)
{
    std::ofstream file(path.c_str());

    if(file)
    {
        file << value;
    }
}

std::string escape(std::string const &s)
{
    std::size_t n = s.length();
    std::string escaped;
    escaped.reserve(n * 2);        // pessimistic preallocation

    for (std::size_t i = 0; i < n; ++i) {
        if (s[i] == '\\' || s[i] == '\'')
            escaped += '\\';
        escaped += s[i];
    }
    return escaped;
}

std::string htmlSpecialChars(std::string const &s)
{
    std::size_t n = s.length();
    std::string escaped;
    escaped.reserve(n * 2);        // pessimistic preallocation

    for (std::size_t i = 0; i < n; ++i) {
        if (s[i] == '>')
        {
            escaped += "&gt;";
        }
        else if (s[i] == '<')
        {
            escaped += "&lt;";
        }
        else
        {
            escaped += s[i];
        }
    }
    return escaped;
}

std::string genRandom(const int len)
{
    srand(time(NULL));

    std::string s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i)
    {
        s += var2Str(alphanum[rand() % (sizeof(alphanum) - 1)]);
    }

    return s;
}

std::string replaceBy(std::string input, std::string what, std::string by)
{
    std::regex regReplace("(" + what + ")");
    return std::regex_replace (input, regReplace, by);
}

bool str2Bool(std::string x)
{
    std::transform(x.begin(), x.end(), x.begin(), ::tolower);
    std::istringstream is(x);
    bool b;
    is >> std::boolalpha >> b;
    return b;
}

bool bin2Bool(std::string x)
{
    if(x == "0")
    {
        return false;
    }
    else
    {
        return true;
    }
}

int bool2bin(bool x)
{
    if(x == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

std::string getSha1(std::string str)
{
    unsigned char result[20];
    char hexstring[41];
    sha1::calc(str.c_str(), str.length(), result); // 10 is the length of the string
    sha1::toHexString(result, hexstring);
    return var2Str(hexstring);

}

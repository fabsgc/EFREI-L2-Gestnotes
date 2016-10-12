/*\
 | ------------------------------------------------------
 | @file : Sql.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe de surcouche de l'API SQL C permettant de simplifier son utilisation
 | ------------------------------------------------------
\*/

#ifndef SQL_HPP_INCLUDED
#define SQL_HPP_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include "../Database/Database.hpp"

    namespace core
    {
        class Sql
        {
            public :
                            Sql(Database& database);
                            ~Sql();
                void        var(std::string name, std::string value);
                void        var(std::string name, int value);
                void        var(std::string name, float value);
                void        query(std::string value);
                bool        execute();
                dataMap    fetch();

            private :
                std::string parse();
                std::string escapeString(const std::string & data);

            private :
                Database&   mDatabase;
                stringMap mVars;
                std::string mQuery;
        };
    }

#endif // SQL_HPP_INCLUDED

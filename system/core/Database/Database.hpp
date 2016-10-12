/*\
 | ------------------------------------------------------
 | @file : Database.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : On encapsule la connexion à la base de données (DAO)
 | ------------------------------------------------------
\*/

#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

#include "../../include.hpp"

    namespace core
    {
        class Database
        {
            public :
                       Database();
                       ~Database();
                void   init(stringMap db);
                MYSQL* getDb();
                int    getLastInsertId();

            private :
                MYSQL* mMysql;
        };
    }

#endif // DATABASE_HPP_INCLUDED

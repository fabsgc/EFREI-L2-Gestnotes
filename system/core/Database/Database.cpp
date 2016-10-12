/*\
 | ------------------------------------------------------
 | @file : Database.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : On encapsule la connexion à la base de données (DAO)
 | ------------------------------------------------------
\*/

#include "Database.hpp"

    namespace core
    {
        Database::Database()
        {

        }

        void Database::init(stringMap db)
        {
            const char *server   = db["host"].c_str();
            const char *user     = db["user"].c_str();
            const char *password = db["password"].c_str();
            const char *database = db["database"].c_str();

            mMysql = mysql_init(NULL);
            if (!mysql_real_connect(mMysql, server, user, password, database, 0, NULL, 0))
            {
                fprintf(stderr, "%s\n", mysql_error(mMysql));
            }
            else
            {
                mysql_query(mMysql, "SET CHARACTER SET utf8");
            }
        }

        MYSQL * Database::getDb()
        {
            return mMysql;
        }

        int Database::getLastInsertId()
        {
            return mysql_insert_id(mMysql);
        }

        Database::~Database()
        {

        }
    }

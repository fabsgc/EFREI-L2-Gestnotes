/*\
 | ------------------------------------------------------
 | @file : Sql.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe de surcouche de l'API SQL C permettant de simplifier son utilisation
 | ------------------------------------------------------
\*/

#include "Sql.hpp"

    namespace core
    {
        Sql::Sql(Database& database) :
        mDatabase(database)
        {

        }

        void Sql::var(std::string name, std::string value)
        {
            mVars[name] = value;
        }

        void Sql::var(std::string name, int value)
        {
            mVars[name] = var2Str(value);
        }

        void Sql::var(std::string name, float value)
        {
            mVars[name] = var2Str(value);
        }

        void Sql::query(std::string value)
        {
            mQuery = value;
        }

        bool Sql::execute()
        {
            if(mQuery.size() > 0)
            {
                MYSQL * mysql     = mDatabase.getDb();
                std::string query = parse();

                std::ofstream log("app/log/sql.log", std::ios_base::app | std::ios_base::out);
                log << query + "\n";
                log << "#################################################################\n";

                mysql_query(mysql, query.c_str());
            }

            return true;
        }

        dataMap Sql::fetch()
        {
            dataMap data;

            if(mQuery.size() > 0)
            {
                MYSQL_ROW     row;
                MYSQL_FIELD * field;
                MYSQL_RES *   result;
                MYSQL * mysql     = mDatabase.getDb();
                std::string query = parse();
                int i             = 0;
                int numField      = 0;

                std::ofstream log("app/log/sql.log", std::ios_base::app | std::ios_base::out);
                log << query + "\n";
                log << "#################################################################\n";

                mysql_query(mysql, query.c_str());
                result   = mysql_store_result(mysql);
                numField = mysql_num_fields(result);
                char * headers[numField];

                for(i = 0; (field = mysql_fetch_field(result)); i++) {
                    headers[i] = field->name;
                }

                i = 0;

                while ((row = mysql_fetch_row(result)))
                {
                    stringMap line;

                    for(int j = 0; j < numField; j++)
                    {
                        line[var2Str(headers[j])] = var2Str(row[j]);
                    }

                    data[var2Str(i)] = line;
                    i++;
                }

                mysql_free_result(result);
            }

            return data;
        }

        std::string Sql::parse()
        {
            std::string query = mQuery;

            for(auto i = mVars.begin(); i != mVars.end(); i++)
            {
                query = replaceBy(query, ":" + i->first, "\"" + i->second + "\"");
            }

            return query;
        }

        std::string Sql::escapeString(const std::string & data) {
            std::string result;
            const char *pStr = data.c_str();

            while (*pStr)
            {
                if (!strchr("\"'\r\n\t",*pStr))
                {
                    result.push_back(*pStr);
                }

                ++pStr;
            }

            return result;
        }

        Sql::~Sql()
        {

        }
    }

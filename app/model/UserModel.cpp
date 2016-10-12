/*\
 | ------------------------------------------------------
 | @file : UserModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des utilisateurs
 | ------------------------------------------------------
\*/

#include "UserModel.hpp"

    namespace app
    {
        UserModel::UserModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        dataMap UserModel::getUserById(std::string id, std::string password, std::string type)
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("password", getSha1(password));

            if(type == USER_ADMIN)
            {
                sql.query("SELECT *, a.id as uid FROM admin a INNER JOIN person_detail p ON a.person_detail_id = p.id WHERE a.id = :id AND a.password = :password");
            }
            else if(type == USER_TEACHER)
            {
                sql.query("SELECT *, t.id as uid FROM teacher t INNER JOIN person_detail p ON t.person_detail_id = p.id WHERE t.id = :id AND t.password = :password");
            }
            else
            {
                sql.query("SELECT *, s.id as uid FROM student s INNER JOIN person_detail p ON s.person_detail_id = p.id WHERE s.id = :id AND s.password = :password");
            }

            dataMap data;

            return sql.fetch();
        }

        entity::Student UserModel::getStudentById(std::string id)
        {
            entity::Student student(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.query("SELECT id FROM student WHERE id = :id");
            data = sql.fetch();

            if(data.size() == 1)
            {
                student.hydrate(data["0"]["id"]);
            }

            return student;
        }

        entity::Teacher UserModel::getTeacherById(std::string id)
        {
            entity::Teacher teacher(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.query("SELECT id FROM teacher WHERE id = :id");
            data = sql.fetch();

            if(data.size() == 1)
            {
                teacher.hydrate(data["0"]["id"]);
            }

            return teacher;
        }

        entity::Admin UserModel::getAdminById(std::string id)
        {
            entity::Admin admin(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.query("SELECT id FROM admin WHERE id = :id");
            data = sql.fetch();

            if(data.size() == 1)
            {
                admin.hydrate(data["0"]["id"]);
            }

            return admin;
        }
    }

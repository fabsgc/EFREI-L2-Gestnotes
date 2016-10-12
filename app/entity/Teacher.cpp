/*\
 | ------------------------------------------------------
 | @file : Teacher.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représantant la table teacher
 | ------------------------------------------------------
\*/

#include "Teacher.hpp"

    namespace entity
    {
        Teacher::Teacher(core::Database& database) :
        Person::Person(database)
        {

        }

        void Teacher::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            stringMap data;
            dataMap   datas;
            id = key;

            sql.var("id", id);
            sql.query("SELECT * FROM teacher WHERE id = :id");
            datas = sql.fetch();

            if(datas.size() == 1)
            {
                data = datas["0"];
                password = data["password"];
                personDetail.hydrate(data["person_detail_id"]);
                validEntity = true;
            }
            else
            {
                validEntity = false;
            }
        }

        void Teacher::save()
        {
            personDetail.save();

            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("password", password);
            sql.var("personDetail", personDetail.id);

            sql.query("INSERT INTO teacher(id, password, person_detail_id) VALUES(:id, :password, :personDetail)");
            sql.execute();
        }

        void Teacher::update()
        {
            personDetail.update();

            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("password", password);
            sql.var("personDetail", personDetail.id);

            sql.query("UPDATE teacher SET password = :password, person_detail_id = :personDetail WHERE id = :id");
            sql.execute();
        }

        void Teacher::destroy()
        {
            core::Sql sql(mDatabase);

            sql.var("id", id);
            sql.var("personDetail", personDetail.id);

            sql.query("DELETE FROM teacher WHERE id = :id");
            sql.execute();
            sql.query("DELETE FROM person_detail WHERE id = :personDetail");
            sql.execute();
            sql.query("DELETE FROM l_course_teacher_assistant WHERE teacher_id = :id");
            sql.execute();

        }

        Teacher& Teacher::operator=(const Teacher& teacher)
        {
            id = teacher.id;
            password = teacher.password;
            personDetail = teacher.personDetail;
            validEntity = teacher.validEntity;
            mDatabase = teacher.mDatabase;

            return *this;
        }

        Teacher::~Teacher()
        {

        }
    }

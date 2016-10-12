/*\
 | ------------------------------------------------------
 | @file : Mark.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table mark
 | ------------------------------------------------------
\*/

#include "Mark.hpp"

    namespace entity
    {
        Mark::Mark(core::Database& database) :
        Entity::Entity(database),
        student(database),
        course(database)
        {

        }

        void Mark::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            stringMap data;
            dataMap   datas;
            id = std::stoi(key);

            sql.var("id", id);
            sql.query("SELECT * FROM mark WHERE id = :id");
            datas = sql.fetch();

            if(datas.size() == 1)
            {
                data = datas["0"];
                coeff = std::stof(data["coeff"]);
                value = std::stof(data["value"]);
                type  = std::stoi(data["type"]);

                sql.var("course", data["course_id"]);
                sql.var("student", data["student_id"]);

                sql.query("SELECT * FROM course WHERE id = :course");
                datas = sql.fetch();

                if(datas.size() == 1)
                {
                    course.hydrate(datas["0"]["id"]);
                }

                sql.query("SELECT * FROM student WHERE id = :student");
                datas = sql.fetch();

                if(datas.size() == 1)
                {
                    student.hydrate(datas["0"]["id"]);
                }

                validEntity = true;
            }
        }

        void Mark::save()
        {
            core::Sql sql(mDatabase);
            sql.var("value", value);
            sql.var("coeff", coeff);
            sql.var("type", type);
            sql.var("course", course.id);
            sql.var("student", student.id);

            sql.query("INSERT INTO mark(type, value, coeff, course_id, student_id) VALUES(:type, :value, :coeff, :course, :student)");
            sql.execute();

            id = mDatabase.getLastInsertId();
        }

        void Mark::update()
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("value", value);
            sql.var("coeff", coeff);
            sql.var("type", type);
            sql.var("course", course.id);
            sql.var("student", student.id);

            sql.query("UPDATE mark SET type = :type, value = :value, coeff = :coeff, course_id = :course, student_id = :student WHERE id = :id");
            sql.execute();
        }

        void Mark::destroy()
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);

            sql.query("DELETE FROM mark WHERE id = :id");
            sql.execute();
        }

        Mark& Mark::operator=(const Mark& mark)
        {
            id = mark.id;
            type = mark.type;
            value = mark.value;
            coeff = mark.coeff;
            course = mark.course;
            student = mark.student;
            validEntity = mark.validEntity;

            return *this;
        }

        Mark::~Mark()
        {

        }
    }

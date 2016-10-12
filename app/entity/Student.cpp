/*\
 | ------------------------------------------------------
 | @file : Student.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représantant la table student
 | ------------------------------------------------------
\*/

#include "Student.hpp"

    namespace entity
    {
        Student::Student(core::Database& database) :
        Person::Person(database),
        contact(database),
        teacher(database)
        {

        }

        void Student::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            stringMap data;
            dataMap   datas;
            id = key;

            sql.var("id", id);
            sql.query("SELECT * FROM student WHERE id = :id");
            datas = sql.fetch();

            if(datas.size() == 1)
            {
                data = datas["0"];
                password = data["password"];
                group     = std::stoul(data["group_id"]);
                successYear = bin2Bool(data["success_year"]);
                personDetail.hydrate(data["person_detail_id"]);

                sql.var("teacher", data["teacher_id"]);
                sql.var("contact", data["contact_id"]);

                sql.query("SELECT * FROM teacher WHERE id = :teacher");
                datas = sql.fetch();

                if(datas.size() == 1)
                {
                    teacher.hydrate(datas["0"]["id"]);
                }

                sql.query("SELECT * FROM contact WHERE id = :contact");
                datas = sql.fetch();

                if(datas.size() == 1)
                {
                    contact.hydrate(datas["0"]["id"]);
                }

                validEntity = true;
            }
        }

        void Student::save()
        {
            personDetail.save();

            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("password", password);
            sql.var("successYear", bool2bin(successYear));
            sql.var("personDetail", personDetail.id);
            sql.var("contact", contact.id);
            sql.var("group", group);
            sql.var("teacher", teacher.id);

            sql.query("INSERT INTO student(id, password, success_year, person_detail_id, contact_id, group_id, teacher_id) VALUES(:id, :password, :successYear, :personDetail, :contact, :group, :teacher)");
            sql.execute();
        }

        void Student::update()
        {
            personDetail.update();

            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("password", password);
            sql.var("successYear", bool2bin(successYear));
            sql.var("personDetail", personDetail.id);
            sql.var("contact", contact.id);
            sql.var("group", group);
            sql.var("teacher", teacher.id);

            sql.query("UPDATE student SET password = :password, success_year = :successYear, person_detail_id = :personDetail, contact_id = :contact, group_id = :group, teacher_id = :teacher WHERE id = :id");
            sql.execute();
        }

        void Student::destroy()
        {
            core::Sql sql(mDatabase);

            sql.var("id", id);
            sql.var("personDetail", personDetail.id);

            sql.query("DELETE FROM student WHERE id = :id");
            sql.execute();
            sql.query("DELETE FROM person_detail WHERE id = :personDetail");
            sql.execute();
            sql.query("DELETE FROM l_group_student WHERE student_id = :id");
            sql.execute();
        }

        Student Student::operator=(const Student& student)
        {
            id = student.id;
            password = student.password;
            successYear = student.successYear;
            personDetail = student.personDetail;
            teacher = student.teacher;
            contact = student.contact;
            validEntity = student.validEntity;
            group = student.group;
            mDatabase   = student.mDatabase;

            return *this;
        }

        Student::~Student()
        {

        }
    }

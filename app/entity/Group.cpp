/*\
 | ------------------------------------------------------
 | @file : Group.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table groups
 | ------------------------------------------------------
\*/

#include "Group.hpp"

    namespace entity
    {
        Group::Group(core::Database& database) :
        Entity::Entity(database)
        {

        }

        void Group::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            stringMap data;
            dataMap   datas;
            id = std::stoul(key);

            sql.var("id", id);
            sql.query("SELECT * FROM groups WHERE id = :id");
            datas = sql.fetch();

            if(datas.size() == 1)
            {
                data = datas["0"];
                name = data["name"];

                sql.query("SELECT * FROM student WHERE group_id = :id");
                datas = sql.fetch();

                for(auto i = datas.begin(); i != datas.end(); i++)
                {
                    Student student(mDatabase);
                    student.hydrate(i->second["id"]);
                    students.push_back(student);
                }

                validEntity = true;
            }
            else
            {
                validEntity = false;
            }
        }

        void Group::save()
        {
            core::Sql sql(mDatabase);
            sql.var("name", name);

            sql.query("INSERT INTO groups(name) VALUES(:name)");
            sql.execute();

            id = mDatabase.getLastInsertId();

            for(auto i = students.begin(); i != students.end(); i++)
            {
                sql.var("student", i->id);
                sql.query("UPDATE student SET group_id = :id WHERE id = :student");
                sql.execute();
            }
        }

        void Group::update()
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("name", name);

            sql.query("UPDATE groups SET name = :name WHERE id = :id VALUES(:name)");
            sql.execute();

            sql.query("UPDATE student SET group_id = 0 WHERE group_id = :id");
            sql.execute();

            for(auto i = students.begin(); i != students.end(); i++)
            {
                sql.var("student", i->id);
                sql.query("UPDATE student SET group_id = :id WHERE id = :student");
                sql.execute();
            }
        }

        void Group::destroy()
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.query("DELETE FROM groups WHERE id = :id");
            sql.execute();

            sql.query("DELETE FROM l_group_course WHERE group_id = :id");
            sql.execute();

            sql.query("UPDATE student SET group_id = 0 WHERE group_id = :id");
            sql.execute();
        }

        Group& Group::operator=(const Group& group)
        {
            id = group.id;
            name = group.name;
            students = group.students;
            validEntity = group.validEntity;
            mDatabase = group.mDatabase;

            return *this;
        }

        Group::~Group()
        {

        }
    }

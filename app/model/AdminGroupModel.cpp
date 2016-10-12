/*\
 | ------------------------------------------------------
 | @file : AdminGroupModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des groupes par les administrateurs
 | ------------------------------------------------------
\*/

#include "AdminGroupModel.hpp"

    namespace app
    {
        AdminGroupModel::AdminGroupModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Group AdminGroupModel::getGroupById(std::string id)
        {
        	entity::Group group(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.query("SELECT id FROM groups WHERE id = :id");
            data = sql.fetch();

            if(data.size() == 1)
            {
                group.hydrate(data["0"]["id"]);
            }

            return group;
        }

        std::vector<entity::Group> AdminGroupModel::getGroups()
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Group> groups;

            sql.query("SELECT id FROM groups ORDER BY name ASC");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Group teacher(mDatabase);
                teacher.hydrate(i->second["id"]);
                groups.push_back(teacher);
            }

            return groups;
        }

        std::vector<entity::Student> AdminGroupModel::getStudentsByGroup(std::string id)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Student> students;

            sql.var("id", id);
            sql.query("SELECT id FROM student WHERE group_id = :id");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Student student(mDatabase);
                student.hydrate(i->second["id"]);
                students.push_back(student);
            }

            return students;
        }

        std::vector<entity::Student> AdminGroupModel::getStudentsNotInGroup()
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Student> students;

            sql.query("SELECT id FROM student WHERE group_id = 0");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Student student(mDatabase);
                student.hydrate(i->second["id"]);
                students.push_back(student);
            }

            return students;
        }

        std::vector<entity::Student> AdminGroupModel::getStudentsNotInGroupAndThisGroup(std::string id)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Student> students;

            sql.var("id", id);
            sql.query("SELECT id FROM student WHERE group_id = 0 OR group_id = :id");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Student student(mDatabase);
                student.hydrate(i->second["id"]);
                students.push_back(student);
            }

            return students;
        }

        std::vector<entity::Student> AdminGroupModel::getStudentsThisGroup(std::string id)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Student> students;

            sql.var("id", id);
            sql.query("SELECT id FROM student WHERE group_id = :id");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Student student(mDatabase);
                student.hydrate(i->second["id"]);
                students.push_back(student);
            }

            return students;
        }
    }

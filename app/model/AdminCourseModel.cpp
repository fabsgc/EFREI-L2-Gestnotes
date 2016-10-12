/*\
 | ------------------------------------------------------
 | @file : AdminCourseModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des cours par les administrateurs
 | ------------------------------------------------------
\*/

#include "AdminCourseModel.hpp"

    namespace app
    {
        AdminCourseModel::AdminCourseModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Teacher AdminCourseModel::getTeacherById(std::string id)
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

        entity::Course AdminCourseModel::getCourseById(std::string id)
        {
        	entity::Course course(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.query("SELECT id FROM course WHERE id = :id");
            data = sql.fetch();

            if(data.size() == 1)
            {
                course.hydrate(data["0"]["id"]);
            }

            return course;
        }

        std::vector<entity::Group> AdminCourseModel::getGroups()
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

        std::vector<entity::Course> AdminCourseModel::getCourses()
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Course> courses;

            sql.query("SELECT id FROM course ORDER BY id DESC");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Course course(mDatabase);
                course.hydrate(i->second["id"]);
                courses.push_back(course);
            }

            return courses;
        }

        std::vector<entity::Teacher> AdminCourseModel::getTeachers()
        {
            core::Sql sql(mDatabase);
        	dataMap data;
            std::vector<entity::Teacher> teachers;

            sql.query("SELECT id FROM teacher ORDER BY id DESC");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Teacher teacher(mDatabase);
                teacher.hydrate(i->second["id"]);
                teachers.push_back(teacher);
            }

            return teachers;
        }
    }

/*\
 | ------------------------------------------------------
 | @file : AdminTeacherModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des professeurs par les administrateurs
 | ------------------------------------------------------
\*/

#include "AdminTeacherModel.hpp"

    namespace app
    {
        AdminTeacherModel::AdminTeacherModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Teacher AdminTeacherModel::getTeacherById(std::string id)
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

        std::vector<entity::Teacher> AdminTeacherModel::getTeachers()
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

        int AdminTeacherModel::getLastTeacherId()
        {
        	core::Sql sql(mDatabase);
            dataMap data;

            sql.query("SELECT id FROM teacher ORDER BY id DESC LIMIT 0,1");
            data = sql.fetch();

            std::regex reg("teacher(.*)");

            return std::stoi(std::regex_replace (data["0"]["id"], reg, "$1"));
        }

        std::vector<entity::Student> AdminTeacherModel::getStudentsTeacher(std::string id)
        {
            core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Student> students;

            sql.var("id", id);
            sql.query("SELECT id FROM student WHERE teacher_id = :id");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Student student(mDatabase);
                student.hydrate(i->second["id"]);
                students.push_back(student);
            }

            return students;
        }

        std::vector<entity::Course> AdminTeacherModel::getCoursesTeacher(std::string id)
        {
            core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Course> courses;

            sql.var("id", id);
            sql.query("SELECT id FROM course WHERE teacher_id = :id");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Course course(mDatabase);
                course.hydrate(i->second["id"]);
                courses.push_back(course);
            }

            return courses;
        }
    }

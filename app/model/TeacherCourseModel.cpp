/*\
 | ------------------------------------------------------
 | @file : TeacherCourseModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des cours par les professeurs
 | ------------------------------------------------------
\*/

#include "TeacherCourseModel.hpp"

    namespace app
    {
        TeacherCourseModel::TeacherCourseModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Teacher TeacherCourseModel::getTeacherById(std::string id)
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

        std::vector<entity::Course> TeacherCourseModel::getCoursesByTeacherPrincipal(entity::Teacher teacher)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Course> courses;

            sql.var("teacher", teacher.id);
            sql.query("SELECT * FROM course WHERE teacher_id = :teacher");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Course course(mDatabase);
                course.hydrate(i->second["id"]);
                courses.push_back(course);
            }

            return courses;
        }

        std::vector<entity::Course> TeacherCourseModel::getCoursesByTeacherAssistant(entity::Teacher teacher)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Course> courses;

            sql.var("teacher", teacher.id);
            sql.query("SELECT * FROM l_course_teacher_assistant WHERE teacher_id = :teacher");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Course course(mDatabase);
                course.hydrate(i->second["course_id"]);
                courses.push_back(course);
            }

            return courses;
        }
    }

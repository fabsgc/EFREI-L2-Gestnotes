/*\
 | ------------------------------------------------------
 | @file : StudentCourseModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des cours par les élèves
 | ------------------------------------------------------
\*/

#include "StudentCourseModel.hpp"

    namespace app
    {
        StudentCourseModel::StudentCourseModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Student StudentCourseModel::getStudentById(std::string id)
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

        std::vector<entity::Course> StudentCourseModel::getCoursesByStudent(entity::Student student)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Course> courses;

            sql.var("group", student.group);
            sql.query("SELECT course_id FROM l_group_course WHERE group_id = :group");
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

/*\
 | ------------------------------------------------------
 | @file : StudentMarkModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des notes par les élèves
 | ------------------------------------------------------
\*/

#include "StudentMarkModel.hpp"

    namespace app
    {
        StudentMarkModel::StudentMarkModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Student StudentMarkModel::getStudentById(std::string id)
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

        entity::ReportCard StudentMarkModel::getReportByStudent(std::string student)
        {
        	entity::ReportCard report(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("student", student);
            sql.query("SELECT id FROM report_card WHERE student_id = :student");
            data = sql.fetch();

            if(data.size() == 1)
            {
                report.hydrate(data["0"]["id"]);
            }

            return report;
        }

        std::vector<entity::Mark> StudentMarkModel::getMarksByStudent(std::string student)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Mark> marks;

            sql.var("student", student);
            sql.query("SELECT id FROM mark WHERE student_id = :student ORDER BY course_id ASC");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Mark mark(mDatabase);
                mark.hydrate(i->second["id"]);
                marks.push_back(mark);
            }

            return marks;
        }

        std::vector<entity::Course> StudentMarkModel::getCoursesByStudent(entity::Student student)
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

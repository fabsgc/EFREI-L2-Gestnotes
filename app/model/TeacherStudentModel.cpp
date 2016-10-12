/*\
 | ------------------------------------------------------
 | @file : TeacherStudentModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des élèves par les professeurs
 | ------------------------------------------------------
\*/

#include "TeacherStudentModel.hpp"

    namespace app
    {
        TeacherStudentModel::TeacherStudentModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Teacher TeacherStudentModel::getTeacherById(std::string id)
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

        std::vector<entity::Student> TeacherStudentModel::getStudentsByTeacher(std::string teacher)
        {
            core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Student> students;

            sql.var("teacher", teacher);
            sql.query("SELECT id FROM student WHERE teacher_id = :teacher");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Student student(mDatabase);
                student.hydrate(i->second["id"]);
                students.push_back(student);
            }

            return students;
        }

        std::vector<entity::Mark> TeacherStudentModel::getMarks()
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Mark> marks;

            sql.query("SELECT id FROM mark");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Mark mark(mDatabase);
                mark.hydrate(i->second["id"]);
                marks.push_back(mark);
            }

            return marks;
        }
    }

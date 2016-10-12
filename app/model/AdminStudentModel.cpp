/*\
 | ------------------------------------------------------
 | @file : AdminTeacherModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des professeurs par les administrateurs
 | ------------------------------------------------------
\*/

#include "AdminStudentModel.hpp"

    namespace app
    {
        AdminStudentModel::AdminStudentModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Student AdminStudentModel::getStudentById(std::string id)
        {
            entity::Student student(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.query("SELECT id FROM student WHERE id = :id");
            data = sql.fetch();

            if(data.size() == 1)
                student.hydrate(data["0"]["id"]);

            return student;
        }

        entity::Contact AdminStudentModel::getContactById(std::string id)
        {
            entity::Contact contact(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.query("SELECT id FROM contact WHERE id = :id");
            data = sql.fetch();

            if(data.size() == 1)
            {
                contact.hydrate(data["0"]["id"]);
            }

            return contact;
        }

        entity::Teacher AdminStudentModel::getTeacherById(std::string id)
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

        std::vector<entity::Contact> AdminStudentModel::getContacts()
        {
            core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Contact> contacts;

            sql.query("SELECT id FROM contact ORDER BY id DESC");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Contact contact(mDatabase);
                contact.hydrate(i->second["id"]);
                contacts.push_back(contact);
            }

            return contacts;
        }

        std::vector<entity::Teacher> AdminStudentModel::getTeachers()
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

        std::vector<entity::Student> AdminStudentModel::getStudents(std::string search)
        {
            core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Student> students;

            if(search =="")
            {
                sql.query("SELECT s.id FROM student s INNER JOIN person_detail p ON p.id = s.person_detail_id ORDER BY p.name ASC");
            }
            else
            {
                search = "%" + search + "%";
                sql.var("search", search);
                sql.query("SELECT s.id FROM student s INNER JOIN person_detail p ON p.id = s.person_detail_id WHERE p.name LIKE :search ORDER BY p.name ASC");
            }

            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Student student(mDatabase);
                student.hydrate(i->second["id"]);
                students.push_back(student);
            }

            return students;
        }

        int AdminStudentModel::getLastUserId()
        {
            core::Sql sql(mDatabase);
            dataMap data;

            sql.query("SELECT id FROM student ORDER BY id DESC LIMIT 0,1");
            data = sql.fetch();

            return std::stoi(data["0"]["id"]);
        }

        entity::Group AdminStudentModel::getGroupById(std::string id)
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

        std::vector<entity::Course> AdminStudentModel::getCoursesByGroup(std::string id)
        {
            std::vector<entity::Course> courses;
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.query("SELECT course_id FROM l_group_course WHERE group_id = :id");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Course course(mDatabase);
                course.hydrate(i->second["course_id"]);
                courses.push_back(course);
            }

            return courses;
        }

        bool AdminStudentModel::checkMarkEnough(entity::Student student)
        {
            entity::Group group = getGroupById(var2Str(student.group));
            std::vector<entity::Course> courses = getCoursesByGroup(var2Str(group.id));

            //Pour chaque cours, on regarde si les examens qui ont un coefficient > 0 on bien une note pour l'élève
            for(auto i = courses.begin(); i != courses.end(); i++)
            {
                if(!checkMarkByStudentByCourseByType(student, *i, "1"))
                {
                    return false;
                }

                if(!checkMarkByStudentByCourseByType(student, *i, "2"))
                {
                    return false;
                }

                if(!checkMarkByStudentByCourseByType(student, *i, "3"))
                {
                    return false;
                }

                if(!checkMarkByStudentByCourseByType(student, *i, "4"))
                {
                    return false;
                }
            }

            return true;
        }

        bool AdminStudentModel::checkMarkByStudentByCourseByType(entity::Student student, entity::Course course, std::string type)
        {
            if((type == "1" && course.coeffCe == 0) || (type == "2" && course.coeffDe == 0) || (type == "3" && course.coeffTp == 0) || (type == "4" && course.coeffProject == 0))
                return true;

            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("student", student.id);
            sql.var("course", course.id);
            sql.var("type", type);
            sql.query("SELECT * FROM mark WHERE student_id = :student AND course_id = :course AND type = :type");
            data = sql.fetch();

            if(data.size() == 1)
                return true;

            return false;
        }
    }

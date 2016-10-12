/*\
 | ------------------------------------------------------
 | @file : Course.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table course
 | ------------------------------------------------------
\*/

#include "Course.hpp"

    namespace entity
    {
        Course::Course(core::Database& database) :
        Entity::Entity(database),
        teacherPrincipal(database)
        {

        }

        void Course::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            stringMap data;
            dataMap   datas, datas2, datas3;

            id = std::stoi(key);

            sql.var("id", id);
            sql.query("SELECT * FROM course WHERE id = :id");
            datas = sql.fetch();

            if(datas.size() == 1)
            {
                data = datas["0"];
                name = data["name"];
                coeffCe = std::stof(data["coeff_ce"]);
                coeffDe = std::stof(data["coeff_de"]);
                coeffTp = std::stof(data["coeff_tp"]);
                coeffProject = std::stof(data["coeff_project"]);

                sql.var("teacher", data["teacher_id"]);
                sql.query("SELECT * FROM teacher WHERE id = :teacher");
                datas = sql.fetch();

                if(datas.size() == 1)
                {
                    teacherPrincipal.hydrate(datas["0"]["id"]);
                }

                sql.query("SELECT * FROM l_course_teacher_assistant WHERE course_id = :id");
                datas = sql.fetch();

                for(auto i = datas.begin(); i != datas.end(); i++)
                {
                    entity::Teacher teacherAssistant(mDatabase);
                    teacherAssistant.hydrate(i->second["teacher_id"]);
                    teachersAssistant.push_back(teacherAssistant);
                }

                sql.query("SELECT * FROM l_group_course WHERE course_id = :id");
                datas = sql.fetch();

                for(auto i = datas.begin(); i != datas.end(); i++)
                {
                    entity::Group group(mDatabase);
                    group.hydrate(i->second["group_id"]);
                    groups.push_back(group);
                }

                sql.query("SELECT s.id as student FROM l_group_course lgc INNER JOIN student s ON lgc.group_id = s.id WHERE lgc.course_id = :id");
                datas = sql.fetch();

                for(auto i = datas.begin(); i != datas.end(); i++)
                {
                    entity::Student student(mDatabase);
                    student.hydrate(i->second["student"]);
                    students.push_back(student);
                }

                validEntity = true;
            }
            else
            {
                validEntity = false;
            }
        }

        void Course::save()
        {
            core::Sql sql(mDatabase);
            sql.var("name", name);
            sql.var("coeffCe", coeffCe);
            sql.var("coeffDe", coeffDe);
            sql.var("coeffTp", coeffTp);
            sql.var("coeffProject", coeffProject);
            sql.var("teacher", teacherPrincipal.id);

            sql.query("INSERT INTO course(name, coeff_ce, coeff_de, coeff_tp, coeff_project, teacher_id) VALUES(:name, :coeffCe, :coeffDe, :coeffTp, :coeffProject, :teacher)");
            sql.execute();

            id = mDatabase.getLastInsertId();

            sql.var("id", id);

            for(auto i = groups.begin(); i != groups.end(); i++)
            {
                sql.var("group", i->id);
                sql.query("INSERT INTO l_group_course(course_id, group_id) VALUES(:id, :group)");
                sql.execute();
            }

            for(auto i = teachersAssistant.begin(); i != teachersAssistant.end(); i++)
            {
                sql.var("teacher", i->id);
                sql.query("INSERT INTO l_course_teacher_assistant(course_id, teacher_id) VALUES(:id, :teacher)");
                sql.execute();
            }
        }

        void Course::update()
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("name", name);
            sql.var("coeffCe", coeffCe);
            sql.var("coeffDe", coeffDe);
            sql.var("coeffTp", coeffTp);
            sql.var("coeffProject", coeffProject);
            sql.var("teacher", teacherPrincipal.id);

            sql.query("UPDATE course SET name = :name, coeff_ce = :coeffCe, coeff_de = :coeffDe, coeff_tp = :coeffTp, coeff_project = :coeffProject, teacher_id = :teacher WHERE id = :id");
            sql.execute();

            sql.query("UPDATE mark SET coeff = :coeffCe WHERE type = 1 AND course_id = :id");
            sql.execute();
            sql.query("UPDATE mark SET coeff = :coeffDe WHERE type = 2 AND course_id = :id");
            sql.execute();
            sql.query("UPDATE mark SET coeff = :coeffTp WHERE type = 3 AND course_id = :id");
            sql.execute();
            sql.query("UPDATE mark SET coeff = :coeffProject WHERE type = 4 AND course_id = :id");
            sql.execute();

            sql.query("DELETE FROM l_group_course WHERE course_id = :id");
            sql.execute();

            sql.query("DELETE FROM report_card");
            sql.execute();

            for(auto i = groups.begin(); i != groups.end(); i++)
            {
                sql.var("group", i->id);
                sql.query("INSERT INTO l_group_course(course_id, group_id) VALUES(:id, :group)");
                sql.execute();
            }

            sql.query("DELETE FROM l_course_teacher_assistant WHERE course_id = :id");
            sql.execute();

            for(auto i = teachersAssistant.begin(); i != teachersAssistant.end(); i++)
            {
                sql.var("teacher", i->id);
                sql.query("INSERT INTO l_course_teacher_assistant(course_id, teacher_id) VALUES(:id, :teacher)");
                sql.execute();
            }
        }

        void Course::destroy()
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.query("DELETE FROM course WHERE id = :id");
            sql.execute();

            sql.query("DELETE FROM l_course_teacher_assistant WHERE course_id = :id");
            sql.execute();

            sql.query("DELETE FROM l_group_course WHERE course_id = :id");
            sql.execute();

            sql.query("DELETE FROM mark WHERE course_id = :id");
            sql.execute();
        }

        Course& Course::operator=(const Course& course)
        {
            id = course.id;
            name = course.name;
            teacherPrincipal = course.teacherPrincipal;
            teachersAssistant = course.teachersAssistant;
            students = course.students;
            groups = course.groups;
            validEntity = course.validEntity;
            mDatabase = course.mDatabase;

            return *this;
        }

        Course::~Course()
        {

        }
    }

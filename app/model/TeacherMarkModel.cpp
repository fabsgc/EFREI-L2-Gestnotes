/*\
 | ------------------------------------------------------
 | @file : TeacherMarkModel.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : modèle gestion des notes par les professeurs
 | ------------------------------------------------------
\*/

#include "TeacherMarkModel.hpp"

    namespace app
    {
        TeacherMarkModel::TeacherMarkModel(core::Config &config, core::Database &database, core::Request &request) :
        Model::Model(config, database, request)
        {

        }

        entity::Teacher TeacherMarkModel::getTeacherById(std::string id)
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

        entity::Course TeacherMarkModel::getCourseById(std::string id, std::string teacher)
        {
        	entity::Course course(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.var("teacher", teacher);
            sql.query("SELECT id FROM course WHERE id = :id AND teacher_id = :teacher");
            data = sql.fetch();

            if(data.size() == 1)
            {
                course.hydrate(data["0"]["id"]);
            }

            return course;
        }

        entity::Group TeacherMarkModel::getGroupById(std::string id, std::string teacher)
        {
        	entity::Group group(mDatabase);
            core::Sql sql(mDatabase);
            dataMap data;

            sql.var("id", id);
            sql.var("teacher", teacher);
            sql.query("SELECT lgc.group_id FROM l_group_course lgc INNER JOIN course c ON c.id = lgc.course_id WHERE c.teacher_id = :teacher AND lgc.group_id = :id GROUP BY lgc.group_id");
            data = sql.fetch();

            if(data.size() == 1)
            {
                group.hydrate(data["0"]["group_id"]);
            }

            return group;
        }

        entity::Student TeacherMarkModel::getStudentById(std::string id)
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

        std::vector<entity::Group> TeacherMarkModel::getGroups(std::string teacher)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Group> groups;

            sql.var("teacher", teacher);
            sql.query("SELECT lgc.group_id FROM l_group_course lgc INNER JOIN course c ON c.id = lgc.course_id WHERE c.teacher_id = :teacher GROUP BY lgc.group_id");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Group teacher(mDatabase);
                teacher.hydrate(i->second["group_id"]);
                groups.push_back(teacher);
            }

            return groups;
        }

        std::vector<entity::Student> TeacherMarkModel::getStudentsByGroupAndCourse(std::string group, std::string course)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Student> students;

            sql.var("group", group);
            sql.var("course", course);
            sql.query("SELECT s.id FROM student s INNER JOIN groups g ON g.id = s.group_id INNER JOIN l_group_course lgc ON lgc.group_id = g.id WHERE s.group_id = :group AND lgc.course_id = :course");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Student student(mDatabase);
                student.hydrate(i->second["id"]);
                students.push_back(student);
            }

            return students;
        }

        std::vector<entity::Course> TeacherMarkModel::getCoursesByGroup(std::string group, std::string teacher)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Course> courses;

            sql.var("group", group);
            sql.var("teacher", teacher);
            sql.query("SELECT lgc.course_id FROM l_group_course lgc INNER JOIN course c ON c.id = lgc.course_id WHERE lgc.group_id = :group AND c.teacher_id = :teacher GROUP BY lgc.course_id");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Course course(mDatabase);
                course.hydrate(i->second["course_id"]);
                courses.push_back(course);
            }

            return courses;
        }

        std::vector<entity::Mark> TeacherMarkModel::getMarksByCourse(std::string course)
        {
			core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::Mark> marks;

            sql.var("course", course);
            sql.query("SELECT id FROM mark WHERE course_id = :course");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::Mark mark(mDatabase);
                mark.hydrate(i->second["id"]);
                marks.push_back(mark);
            }

            return marks;
        }

        bool TeacherMarkModel::checkGroupCourse(std::string course, std::string group)
        {
        	core::Sql sql(mDatabase);
            dataMap data;

            sql.var("group", group);
            sql.var("course", course);
            sql.query("SELECT id FROM l_group_course WHERE course_id = :course AND group_id = :group");
            data = sql.fetch();

            if(data.size() == 1)
            {
            	return true;
            }

            return false;
        }

        bool TeacherMarkModel::markEnabled(entity::Course course)
        {
        	bool markEnabled = true;

            switch (std::stoi(mRequest.get("type"))) {
                case 1:
                    if(course.coeffCe == 0)
                    {
                        markEnabled = false;
                    }
                break;

                case 2:
                    if(course.coeffDe == 0)
                    {
                        markEnabled = false;
                    }
                break;

                case 3:
                    if(course.coeffTp == 0)
                    {
                        markEnabled = false;
                    }
                break;

                case 4:
                    if(course.coeffProject == 0)
                    {
                        markEnabled = false;
                    }
                break;
            }

            return markEnabled;
        }

        bool TeacherMarkModel::checkMarkExist(std::string course, std::string student, std::string type)
        {
        	core::Sql sql(mDatabase);
            dataMap data;

            sql.var("course", course);
            sql.var("student", student);
            sql.var("type", type);
            sql.query("SELECT id FROM mark WHERE course_id = :course AND student_id = :student AND type = :type");
            data = sql.fetch();

            if(data.size() == 1)
            {
            	return true;
            }

            return false;
        }

        entity::Mark TeacherMarkModel::getMarkExist(std::string course, std::string student, std::string type)
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            entity::Mark mark(mDatabase);

            sql.var("course", course);
            sql.var("student", student);
            sql.var("type", type);
            sql.query("SELECT id FROM mark WHERE course_id = :course AND student_id = :student AND type = :type");
            data = sql.fetch();

            if(data.size() == 1)
            {
            	mark.hydrate(data["0"]["id"]);
            }

            return mark;
        }

        std::vector<entity::ReportCard> TeacherMarkModel::getReports()
        {
        	core::Sql sql(mDatabase);
            dataMap data;
            std::vector<entity::ReportCard> reports;

            sql.query("SELECT id FROM report_card");
            data = sql.fetch();

            for(auto i = data.begin(); i != data.end(); i++)
            {
                entity::ReportCard report(mDatabase);
                report.hydrate(i->second["id"]);
                reports.push_back(report);
            }

            return reports;
        }
    }

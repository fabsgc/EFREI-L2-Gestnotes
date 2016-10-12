/*\
 | ------------------------------------------------------
 | @file : TeacherStudentController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des notes par les professeurs
 | ------------------------------------------------------
\*/

#include "TeacherMarkController.hpp"

    namespace app
    {
        TeacherMarkController::TeacherMarkController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string TeacherMarkController::home()
        {
            entity::Teacher teacher = mModel.getTeacherById(mSession.get("id"));
            std::vector<entity::Group> groups = mModel.getGroups(teacher.id);

            core::Template tpl("teacherMark/home", "home", mConfig, mRequest);
            tpl.var("title", "Notes");
            tpl.var("filAriane", "Notes");
            tpl.var("groups", groups);
            return tpl.render();
        }

        std::string TeacherMarkController::group()
        {
            entity::Teacher teacher = mModel.getTeacherById(mSession.get("id"));
            entity::Group group = mModel.getGroupById(mRequest.get()["id"], teacher.id);

            if(group.validEntity == true)
            {
                std::vector<entity::Course> courses = mModel.getCoursesByGroup(mRequest.get("id"), teacher.id);

                core::Template tpl("teacherMark/group", "group", mConfig, mRequest);
                tpl.var("title", group.name);
                tpl.var("filAriane", "Notes/" + group.name);
                tpl.var("courses", courses);
                return tpl.render();
            }

            return "status:404";
        }

        std::string TeacherMarkController::course()
        {
            entity::Teacher teacher = mModel.getTeacherById(mSession.get("id"));
            entity::Group group = mModel.getGroupById(mRequest.get()["group"], teacher.id);
            entity::Course course = mModel.getCourseById(mRequest.get()["course"], teacher.id);

            if(group.validEntity == true && course.validEntity == true && mModel.checkGroupCourse(mRequest.get("course"), mRequest.get("group")))
            {
                std::vector<entity::Student> students = mModel.getStudentsByGroupAndCourse(mRequest.get("group"), mRequest.get("course"));
                std::vector<entity::Mark> marks = mModel.getMarksByCourse(mRequest.get("course"));
                std::vector<entity::ReportCard> reports = mModel.getReports();

                core::Template tpl("teacherMark/course", "course", mConfig, mRequest);
                tpl.var("title", course.name);
                tpl.var("filAriane", "Notes/" + group.name + "/" + course.name);
                tpl.var("group", group);
                tpl.var("course", course);
                tpl.var("students", students);
                tpl.var("marks", marks);
                tpl.var("reports", reports);

                return tpl.render();
            }

            return "status:404";
        }

        std::string TeacherMarkController::setMark()
        {
            entity::Teacher teacher = mModel.getTeacherById(mSession.get("id"));
            entity::Group group = mModel.getGroupById(mRequest.get("group"), teacher.id);
            entity::Course course = mModel.getCourseById(mRequest.get("course"), teacher.id);
            entity::Student student = mModel.getStudentById(mRequest.get("student"));

            if(group.validEntity && course.validEntity && student.validEntity && mModel.checkGroupCourse(mRequest.get("course"), mRequest.get("group")) && mModel.markEnabled(course))
            {
                if(std::stod(mRequest.get("value")) >= 0 && std::stod(mRequest.get("value")) <= 20)
                {
                    if(mModel.checkMarkExist(mRequest.get("course"), mRequest.get("student"), mRequest.get("type")))
                    {
                        entity::Mark mark = mModel.getMarkExist(mRequest.get("course"), mRequest.get("student"), mRequest.get("type"));
                        mark.value = std::stod(mRequest.get("value"));
                        mark.update();
                    }
                    else
                    {
                        entity::Mark mark(mDatabase);
                        mark.value = std::stod(mRequest.get("value"));
                        mark.type  = std::stod(mRequest.get("type"));
                        mark.course = course;
                        mark.student = student;

                        switch (std::stoi(mRequest.get("type"))) {
                            case 1:
                                mark.coeff = course.coeffCe;
                            break;

                            case 2:
                                mark.coeff = course.coeffDe;
                            break;

                            case 3:
                                mark.coeff = course.coeffTp;
                            break;

                            case 4:
                                mark.coeff = course.coeffProject;
                            break;
                        }

                        mark.save();
                    }

                    return var2Str(course.coeffDe);
                }
            }

            return "status:404";
        }
    }

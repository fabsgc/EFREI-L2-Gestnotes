/*\
 | ------------------------------------------------------
 | @file : StudentMarkController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des notes par les élèves
 | ------------------------------------------------------
\*/

#include "StudentMarkController.hpp"

    namespace app
    {
        StudentMarkController::StudentMarkController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string StudentMarkController::home()
        {
            entity::Student student = mModel.getStudentById(mSession.get("id"));
            entity::ReportCard report = mModel.getReportByStudent(student.id);
            std::vector<entity::Mark> marks = mModel.getMarksByStudent(student.id);

            core::Template tpl("studentMark/home", "home", mConfig, mRequest);
            tpl.var("title", "Notes");
            tpl.var("filAriane", "Notes");
            tpl.var("student", student);
            tpl.var("marks", marks);
            tpl.var("report", report.validEntity);

            return tpl.render();
        }

        std::string StudentMarkController::report()
        {
            entity::Student student = mModel.getStudentById(mSession.get("id"));
            entity::ReportCard report = mModel.getReportByStudent(student.id);

            if(report.validEntity)
            {
                std::vector<entity::Mark> marks = mModel.getMarksByStudent(student.id);
                std::vector<entity::Course> courses = mModel.getCoursesByStudent(student);

                core::Template tpl("studentMark/report", "report", mConfig, mRequest);
                tpl.var("title", "Bulletin");
                tpl.var("filAriane", "Notes/Bulletin");
                tpl.var("student", student);
                tpl.var("marks", marks);
                tpl.var("courses", courses);

                return tpl.render();
            }

            return "status:404";
        }
    }

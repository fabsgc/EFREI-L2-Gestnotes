/*\
 | ------------------------------------------------------
 | @file : TeacherStudentController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des élèves par les professeurs
 | ------------------------------------------------------
\*/

#include "TeacherStudentController.hpp"

    namespace app
    {
        TeacherStudentController::TeacherStudentController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string TeacherStudentController::home()
        {
            entity::Teacher teacher = mModel.getTeacherById(mSession.get("id"));
            std::vector<entity::Student> students = mModel.getStudentsByTeacher(teacher.id);
            std::vector<entity::Mark> marks = mModel.getMarks();

            core::Template tpl("teacherStudent/home", "home", mConfig, mRequest);
            tpl.var("title", "Elèves");
            tpl.var("filAriane", "Elèves");
            tpl.var("students", students);
            tpl.var("marks", marks);
            return tpl.render();
        }
    }

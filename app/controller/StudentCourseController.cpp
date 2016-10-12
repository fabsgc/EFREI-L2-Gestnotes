/*\
 | ------------------------------------------------------
 | @file : StudentMarkController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des notes par les élèves
 | ------------------------------------------------------
\*/

#include "StudentCourseController.hpp"

    namespace app
    {
        StudentCourseController::StudentCourseController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string StudentCourseController::home()
        {
            entity::Student student = mModel.getStudentById(mSession.get("id"));
            std::vector<entity::Course> courses = mModel.getCoursesByStudent(student);

            core::Template tpl("studentCourse/home", "home", mConfig, mRequest);
            tpl.var("title", "Cours");
            tpl.var("filAriane", "Cours");
            tpl.var("student", student);
            tpl.var("courses", courses);

            return tpl.render();
        }
    }

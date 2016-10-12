/*\
 | ------------------------------------------------------
 | @file : TeacherCourseController.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : contrôleur gestion des cours par les professeurs
 | ------------------------------------------------------
\*/

#include "TeacherCourseController.hpp"

    namespace app
    {
        TeacherCourseController::TeacherCourseController(core::Config &config, core::Database &database, core::Request &request) :
        Controller::Controller(config, database, request),
        mModel(config, database, request)
        {
        }

        std::string TeacherCourseController::home()
        {
            entity::Teacher teacher = mModel.getTeacherById(mSession.get("id"));
            std::vector<entity::Course> coursesPrincipal = mModel.getCoursesByTeacherPrincipal(teacher);
            std::vector<entity::Course> coursesAssistant = mModel.getCoursesByTeacherAssistant(teacher);

            core::Template tpl("teacherCourse/home", "home", mConfig, mRequest);
            tpl.var("title", "Cours");
            tpl.var("filAriane", "Cours");
            tpl.var("coursesPrincipal", coursesPrincipal);
            tpl.var("coursesAssistant", coursesAssistant);

            return tpl.render();
        }
    }

/*\
 | ------------------------------------------------------
 | @file : Engine.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Le moteur du framework et le point d'entrée de toute requête
 | ------------------------------------------------------
\*/

#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include "../../include.hpp"
#include "../../../app/controller/IndexController.hpp"
#include "../../../app/controller/UserController.hpp"
#include "../../../app/controller/StudentMarkController.hpp"
#include "../../../app/controller/StudentCourseController.hpp"
#include "../../../app/controller/TeacherMarkController.hpp"
#include "../../../app/controller/TeacherCourseController.hpp"
#include "../../../app/controller/TeacherStudentController.hpp"
#include "../../../app/controller/AdminStudentController.hpp"
#include "../../../app/controller/AdminTeacherController.hpp"
#include "../../../app/controller/AdminGroupController.hpp"
#include "../../../app/controller/AdminCourseController.hpp"
#include "../../../app/controller/AdminMarkController.hpp"

    namespace core
    {
        class Engine
        {
            public :
                            Engine();
                            ~Engine();
                void        init();

            private :
                bool        route();
                void        run();
                void        initDatabase();
                bool        checkAuth();
                void        setSessionCookie();

            private :
                Config      mConfig;
                Database    mDatabase;
                Auth        mAuth;
                Request     mRequest;
                Session     mSession;
        };
    }

#endif // ENGINE_HPP_INCLUDED

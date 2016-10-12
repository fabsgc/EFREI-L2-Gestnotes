/*\
 | ------------------------------------------------------
 | @file : Engine.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Le moteur du framework et le point d'entrée de toute requête
 | ------------------------------------------------------
\*/

#include "Engine.hpp"

    namespace core
    {
        Engine::Engine()
        {
        }

        void Engine::init()
        {
            if(route() && checkAuth())
            {
                initDatabase();
                run();
            }
            else
            {
                std::cout << redirect404();
                std::cout << "<h1 style=\"text-align:center;font-family:sans-serif\">404 not found</h1>";
            }
        }

        void Engine::run()
        {
            typedef std::string (app::IndexController::*IndexControllerPtr)();
            typedef std::string (app::UserController::*UserControllerPtr)();
            typedef std::string (app::StudentMarkController::*StudentMarkControllerPtr)();
            typedef std::string (app::StudentCourseController::*StudentCourseControllerPtr)();
            typedef std::string (app::TeacherMarkController::*TeacherMarkControllerPtr)();
            typedef std::string (app::TeacherCourseController::*TeacherCourseControllerPtr)();
            typedef std::string (app::TeacherStudentController::*TeacherStudentControllerPtr)();
            typedef std::string (app::AdminStudentController::*AdminStudentControllerPtr)();
            typedef std::string (app::AdminTeacherController::*AdminTeacherControllerPtr)();
            typedef std::string (app::AdminGroupController::*AdminGroupControllerPtr)();
            typedef std::string (app::AdminCourseController::*AdminCourseControllerPtr)();
            typedef std::string (app::AdminMarkController::*AdminMarkControllerPtr)();

            std::string data = "";

            if(mRequest.getRoute().getController() == "index")
            {
                std::map<std::string,IndexControllerPtr> actions;
                app::IndexController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::IndexController::home;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "user")
            {
                std::map<std::string,UserControllerPtr> actions;
                app::UserController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::UserController::home;
                actions["login"] = &app::UserController::login;
                actions["logout"] = &app::UserController::logout;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "studentMark")
            {
                std::map<std::string,StudentMarkControllerPtr> actions;
                app::StudentMarkController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::StudentMarkController::home;
                actions["report"] = &app::StudentMarkController::report;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "studentCourse")
            {
                std::map<std::string,StudentCourseControllerPtr> actions;
                app::StudentCourseController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::StudentCourseController::home;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "teacherMark")
            {
                std::map<std::string,TeacherMarkControllerPtr> actions;
                app::TeacherMarkController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::TeacherMarkController::home;
                actions["group"] = &app::TeacherMarkController::group;
                actions["course"] = &app::TeacherMarkController::course;
                actions["setMark"] = &app::TeacherMarkController::setMark;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "teacherCourse")
            {
                std::map<std::string,TeacherCourseControllerPtr> actions;
                app::TeacherCourseController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::TeacherCourseController::home;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "teacherStudent")
            {
                std::map<std::string,TeacherStudentControllerPtr> actions;
                app::TeacherStudentController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::TeacherStudentController::home;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "adminStudent")
            {
                std::map<std::string,AdminStudentControllerPtr> actions;
                app::AdminStudentController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::AdminStudentController::home;
                actions["newStudent"] = &app::AdminStudentController::newStudent;
                actions["editStudent"] = &app::AdminStudentController::editStudent;
                actions["deleteStudent"] = &app::AdminStudentController::deleteStudent;
                actions["seeStudent"] = &app::AdminStudentController::seeStudent;
                actions["reportGenerateStudent"] = &app::AdminStudentController::reportGenerateStudent;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "adminTeacher")
            {
                std::map<std::string,AdminTeacherControllerPtr> actions;
                app::AdminTeacherController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::AdminTeacherController::home;
                actions["newTeacher"] = &app::AdminTeacherController::newTeacher;
                actions["editTeacher"] = &app::AdminTeacherController::editTeacher;
                actions["deleteTeacher"] = &app::AdminTeacherController::deleteTeacher;
                actions["seeTeacher"] = &app::AdminTeacherController::seeTeacher;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "adminGroup")
            {
                std::map<std::string,AdminGroupControllerPtr> actions;
                app::AdminGroupController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::AdminGroupController::home;
                actions["newGroup"] = &app::AdminGroupController::newGroup;
                actions["editGroup"] = &app::AdminGroupController::editGroup;
                actions["deleteGroup"] = &app::AdminGroupController::deleteGroup;
                actions["seeGroup"] = &app::AdminGroupController::seeGroup;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "adminCourse")
            {
                std::map<std::string,AdminCourseControllerPtr> actions;
                app::AdminCourseController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::AdminCourseController::home;
                actions["newCourse"] = &app::AdminCourseController::newCourse;
                actions["editCourse"] = &app::AdminCourseController::editCourse;
                actions["deleteCourse"] = &app::AdminCourseController::deleteCourse;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else if(mRequest.getRoute().getController() == "adminMark")
            {
                std::map<std::string,AdminMarkControllerPtr> actions;
                app::AdminMarkController controller(mConfig, mDatabase, mRequest);
                controller.init();
                actions["home"] = &app::AdminMarkController::home;
                actions["group"] = &app::AdminMarkController::group;
                actions["course"] = &app::AdminMarkController::course;
                actions["setMark"] = &app::AdminMarkController::setMark;

                std::string action = mRequest.getRoute().getAction();

                if(actions.find(action) != actions.end())
                {
                    data = (controller.*actions[action])();
                }
            }
            else
            {
                std::cout << redirect404();
                std::cout << "<h1 style=\"text-align:center;font-family:sans-serif\">404 not found</h1>";
            }

            if(data != "status:404")
            {
                std::cout << redirect200();            
                std::cout << data;
            }
            else
            {
                std::cout << redirect404();
                std::cout << "<h1 style=\"text-align:center;font-family:sans-serif\">404 not found</h1>";
            }
        }

        bool Engine::route()
        {
            const std::map<std::string,Route> routes = mConfig.getRoute();
            std::string queryString(getenv("QUERY_STRING"));
            std::string requestUri(getenv("REQUEST_URI"));

            //si on a trouvé au moins une url qui fonctionne même si on est pas connecté/non connecté, on la renvoie
            bool found = false;

            //clean url
            std::regex regCleanUrl ("^(.*)(\\?)(.*)$");
            std::string url = std::regex_replace (requestUri, regCleanUrl, "$1");

            for(auto i = routes.begin(); i != routes.end(); i++)
            {
                if(i->second.match(url))
                {
                    found = true;
                    stringMap vars; //list of get variables
                    std::regex regSplitVars (i->second.getUrl()); //url regex
                    std::string counter  = "";
                    std::vector<std::string> varsList = i->second.getVars(); //list of variable names from route.xml
                    int k = 1;

                    for(auto j = varsList.begin(); j != varsList.end(); j++)
                    {
                        counter = "$" + var2Str(k);
                        vars[*j] = std::regex_replace (url, regSplitVars, counter);
                        k++;
                    }

                    mRequest.init(vars);
                    mRequest.setRoute(i->second);
                    setSessionCookie();
                    mAuth.setCookie(mRequest.cookie());
                    mSession.setCookie(mRequest.cookie());

                    //permet d'avoir la même URL mais menant vers des actions différentes si l'utilisateur est connecté ou non
                    if((i->second.getLogged() == "1" && mSession.exist(mConfig.getAuth()["logged"])) ||
                    (i->second.getLogged() == "0" && !mSession.exist(mConfig.getAuth()["logged"]))   ||
                    (i->second.getLogged() == "*"))
                    {
                        return true;
                    }
                }
            }

            return found;
        }

        void Engine::initDatabase()
        {
            mDatabase.init(mConfig.getDatabase());
        }

        bool Engine::checkAuth()
        {
            return mAuth.check(mRequest.getRoute(), mConfig, mRequest);
        }

        void Engine::setSessionCookie()
        {
            if(mRequest.cookie("sessionid") == "")
            {
                std::cout << "Set-Cookie:sessionid=" + genRandom(64) + ";\r\n";
            }
        }

        Engine::~Engine()
        {

        }
    }

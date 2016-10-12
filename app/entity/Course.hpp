/*\
 | ------------------------------------------------------
 | @file : Course.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table course
 | ------------------------------------------------------
\*/

#ifndef COURSE_HPP_INCLUDED
#define COURSE_HPP_INCLUDED

#include "Group.hpp"
#include "Teacher.hpp"
#include "Student.hpp"

    namespace entity
    {
        class Course : public core::Entity
        {
            public :
                     Course(core::Database& mDatabase);
                     ~Course();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                Course& operator=(const Course& course);

            public :
                int                  id;
                std::string          name;
                float                coeffCe;
                float                coeffDe;
                float                coeffTp;
                float                coeffProject;
                Teacher              teacherPrincipal; //unique
                std::vector<Teacher> teachersAssistant; //unique
                std::vector<Student> students; //unique
                std::vector<Group>   groups;
        };
    }

#endif // COURSE_HPP_INCLUDED

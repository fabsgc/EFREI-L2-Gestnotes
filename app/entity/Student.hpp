/*\
 | ------------------------------------------------------
 | @file : Student.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représantant la table student
 | ------------------------------------------------------
\*/

#ifndef STUDENT_HPP_INCLUDED
#define STUDENT_HPP_INCLUDED

#include "Person.hpp"
#include "Contact.hpp"
#include "Teacher.hpp"

    namespace entity
    {
        class Student : public Person
        {

            public :
                     Student(core::Database& mDatabase);
                     ~Student();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                Student operator=(const Student& student);

            public :
                Contact contact;
                Teacher teacher;
                bool    successYear;
                int     group;
        };
    }

#endif // STUDENT_HPP_INCLUDED

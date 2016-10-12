/*\
 | ------------------------------------------------------
 | @file : Teacher.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représantant la table teacher
 | ------------------------------------------------------
\*/

#ifndef TEACHER_HPP_INCLUDED
#define TEACHER_HPP_INCLUDED

#include "Person.hpp"

    namespace entity
    {
        class Teacher : public Person
        {

            public :
                     Teacher(core::Database& mDatabase);
                     ~Teacher();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                Teacher& operator=(const Teacher& teacher);
        };
    }

#endif // TEACHER_HPP_INCLUDED

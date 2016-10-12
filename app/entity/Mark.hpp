/*\
 | ------------------------------------------------------
 | @file : Mark.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table mark
 | ------------------------------------------------------
\*/

#ifndef MARK_HPP_INCLUDED
#define MARK_HPP_INCLUDED

#include "Student.hpp"
#include "Course.hpp"

    namespace entity
    {
        class Mark : public core::Entity
        {
            public :
                     Mark(core::Database& mDatabase);
                     ~Mark();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                Mark& operator=(const Mark& mark);

            public :
                int     id;
                float   coeff;
                float   value;
                int     type;
                Student student; //unique
                Course  course; //unique
        };
    }

#endif // MARK_HPP_INCLUDED

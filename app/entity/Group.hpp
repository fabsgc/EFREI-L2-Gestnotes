/*\
 | ------------------------------------------------------
 | @file : Group.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table groups
 | ------------------------------------------------------
\*/

#ifndef GROUP_HPP_INCLUDED
#define GROUP_HPP_INCLUDED

#include "Student.hpp"

    namespace entity
    {
        class Group : public core::Entity
        {
            public :
                     Group(core::Database& mDatabase);
                     ~Group();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                Group& operator=(const Group& group);

            public :
                int                  id;
                std::string          name;
                std::vector<Student> students; //unique
        };
    }

#endif // GROUP_HPP_INCLUDED

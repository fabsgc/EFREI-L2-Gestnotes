/*\
 | ------------------------------------------------------
 | @file : Peron.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité abstraite
 | ------------------------------------------------------
\*/

#ifndef PERSON_HPP_INCLUDED
#define PERSON_HPP_INCLUDED

#include "PersonDetail.hpp"

    namespace entity
    {
        class Person : public core::Entity
        {
            public :
                             Person(core::Database& mDatabase);
                virtual      ~Person();
                virtual void hydrate(std::string key);
                virtual void save();
                virtual void update();
                virtual void destroy();
                virtual Person& operator=(const Person& person);

            public :
                std::string  id;
                std::string  password;
                PersonDetail personDetail;
        };
    }


#endif // PERSON_HPP_INCLUDED

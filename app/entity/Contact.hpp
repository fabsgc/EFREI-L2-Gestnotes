/*\
 | ------------------------------------------------------
 | @file : Contact.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table contact
 | ------------------------------------------------------
\*/

#ifndef CONTACT_HPP_INCLUDED
#define CONTACT_HPP_INCLUDED

#include "Person.hpp"

    namespace entity
    {
        class Contact : public Person
        {
            public :
                     Contact(core::Database& mDatabase);
                     ~Contact();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                Contact& operator=(const Contact& contact);
        };
    }

#endif // CONTACT_HPP_INCLUDED

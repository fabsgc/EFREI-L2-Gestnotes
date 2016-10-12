/*\
 | ------------------------------------------------------
 | @file : Admin.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table admin
 | ------------------------------------------------------
\*/

#ifndef ADMIN_HPP_INCLUDED
#define ADMIN_HPP_INCLUDED

#include "Person.hpp"

    namespace entity
    {
        class Admin : public Person
        {
            public :
                     Admin(core::Database& mDatabase);
                     ~Admin();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                Admin& operator=(const Admin& admin);
        };
    }

#endif // ADMIN_HPP_INCLUDED

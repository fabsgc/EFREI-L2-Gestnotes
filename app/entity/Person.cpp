/*\
 | ------------------------------------------------------
 | @file : Peron.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité abstraite
 | ------------------------------------------------------
\*/

#include "Person.hpp"

    namespace entity
    {
        Person::Person(core::Database& database) :
        Entity::Entity(database),
        personDetail(database)
        {

        }

        void Person::hydrate(std::string key)
        {

        }

        void Person::save()
        {

        }

        void Person::update()
        {

        }

        void Person::destroy()
        {

        }

        Person& Person::operator=(const Person& person)
        {
            return *this;
        }

        Person::~Person()
        {

        }
    }

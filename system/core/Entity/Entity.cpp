/*\
 | ------------------------------------------------------
 | @file : Entity.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe abstraite représentant une entité. Une entité est la représentation objet d'une table de la base de données
 | ------------------------------------------------------
\*/

#include "Entity.hpp"

    namespace core
    {
        Entity::Entity(Database& database) :
        mDatabase(database)
        {
            validEntity = false;
        }

        void Entity::hydrate(std::string key)
        {

        }

        Entity::~Entity()
        {

        }
    }

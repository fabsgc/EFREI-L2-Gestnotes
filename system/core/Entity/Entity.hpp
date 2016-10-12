/*\
 | ------------------------------------------------------
 | @file : Entity.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Classe abstraite représentant une entité. Une entité est la représentation objet d'une table de la base de données
 | ------------------------------------------------------
\*/

#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "../../include.hpp"
#include "../Sql/Sql.hpp"

    namespace core
    {
        class Entity
        {
            public :
                             Entity(Database& database);
                virtual      ~Entity() = 0;
                virtual void hydrate(std::string key) = 0;
                virtual void save() = 0;
                virtual void update() = 0;
                virtual void destroy() = 0;

            protected :
                Database&    mDatabase;

            public :
                bool         validEntity;
        };
    }

#endif // ENTITY_HPP_INCLUDED

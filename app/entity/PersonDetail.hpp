/*\
 | ------------------------------------------------------
 | @file : PeronDetail.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représantant la table person_detail
 | ------------------------------------------------------
\*/

#ifndef PERSONDETAIL_HPP_INCLUDED
#define PERSONDETAIL_HPP_INCLUDED

#include "../../system/core/Entity/Entity.hpp"

    namespace entity
    {
        class PersonDetail : public core::Entity
        {

            public :
                     PersonDetail(core::Database& mDatabase);
                     ~PersonDetail();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                PersonDetail& operator=(const PersonDetail& personDetail);

            public :
                int         id;
                int         gender;
                std::string name;
                std::string firstName;
                std::string address;
                std::string city;
                std::string postalCode;
                std::string country;
                std::string email;
                std::string avatar;
                std::string phoneHome;
                std::string phoneMobile;
                std::string dateBorn;
                std::string dateRegister;
        };
    }

#endif // PERSONDETAIL_HPP_INCLUDED

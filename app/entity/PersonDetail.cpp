/*\
 | ------------------------------------------------------
 | @file : PeronDetail.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représantant la table person_detail
 | ------------------------------------------------------
\*/

#include "PersonDetail.hpp"

    namespace entity
    {
        PersonDetail::PersonDetail(core::Database& database) :
        Entity::Entity(database)
        {

        }

        void PersonDetail::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            stringMap data;
            dataMap   datas;

            id = std::stoi(key);

            sql.var("id", id);
            sql.query("SELECT * FROM person_detail WHERE id = :id");
            datas = sql.fetch();

            if(datas.size() == 1)
            {
                data = datas["0"];
                name = data["name"];
                firstName = data["firstname"];
                address = data["address"];
                city = data["city"];
                postalCode = data["postal_code"];
                country = data["country"];
                email = data["email"];
                avatar = data["avatar"];
                phoneHome = data["phone_home"];
                phoneMobile = data["phone_mobile"];
                dateBorn = data["date_born"];
                dateRegister = data["data_register"];
                gender = std::stoi(data["gender"]);
                validEntity = true;
            }
            else
            {
                validEntity = false;
            }
        }

        void PersonDetail::save()
        {
            core::Sql sql(mDatabase);
            sql.var("name", name);
            sql.var("firstname", firstName);
            sql.var("address", address);
            sql.var("city", city);
            sql.var("postalCode", postalCode);
            sql.var("country", country);
            sql.var("avatar", avatar);
            sql.var("email", email);
            sql.var("phoneHome", phoneHome);
            sql.var("phoneMobile", phoneMobile);
            sql.var("dateBorn", dateBorn);
            sql.var("dateRegister", dateRegister);
            sql.var("gender", gender);

            sql.query("INSERT INTO person_detail(name, firstname, address, city, postal_code, country, email, avatar, phone_home, phone_mobile, date_born, date_register, gender)  VALUES(:name, :firstname, :address, :city, :postalCode, :country, :email, :avatar, :phoneHome, :phoneMobile, :dateBorn, :dateRegister, :gender)");
            sql.execute();

            id = mDatabase.getLastInsertId();
        }

        void PersonDetail::update()
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("name", name);
            sql.var("firstname", firstName);
            sql.var("address", address);
            sql.var("city", city);
            sql.var("postalCode", postalCode);
            sql.var("country", country);
            sql.var("avatar", avatar);
            sql.var("email", email);
            sql.var("phoneHome", phoneHome);
            sql.var("phoneMobile", phoneMobile);
            sql.var("dateBorn", dateBorn);
            sql.var("dateRegister", dateRegister);
            sql.var("gender", gender);

            sql.query("UPDATE person_detail SET name = :name, firstname = :firstname, address = :address, city = :city, postal_code = :postalCode, country = :country, email = :email, avatar = :avatar, phone_home = :phoneHome, phone_mobile = :phoneMobile, date_born = :dateBorn, date_register = :dateRegister, gender = :gender WHERE id = :id");
            sql.execute();
        }

        void PersonDetail::destroy()
        {
            core::Sql sql(mDatabase);
            sql.var("id", id);

            sql.query("DELETE FROM person_detail WHERE id = :id");
            sql.execute();
        }

        PersonDetail& PersonDetail::operator=(const PersonDetail& personDetail)
        {
            id = personDetail.id;
            name = personDetail.name;
            firstName = personDetail.firstName;
            address = personDetail.address;
            city = personDetail.city;
            postalCode = personDetail.postalCode;
            country = personDetail.country;
            email = personDetail.email;
            avatar = personDetail.avatar;
            phoneHome = personDetail.phoneHome;
            phoneMobile = personDetail.phoneMobile;
            dateBorn = personDetail.dateBorn;
            dateRegister = personDetail.dateRegister;
            gender = personDetail.gender;
            validEntity = personDetail.validEntity;
            mDatabase = personDetail.mDatabase;

            return *this;
        }

        PersonDetail::~PersonDetail()
        {

        }
    }

/*\
 | ------------------------------------------------------
 | @file : Contact.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table contact
 | ------------------------------------------------------
\*/

#include "Contact.hpp"

    namespace entity
    {
        Contact::Contact(core::Database& database) :
        Person::Person(database)
        {

        }

        void Contact::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            dataMap datas;
            id = key;

            sql.var("id", id);
            sql.query("SELECT * FROM contact WHERE id = :id");
            datas = sql.fetch();

            if(datas.size() == 1)
            {
                password = "";
                personDetail.hydrate(datas["0"]["person_detail_id"]);
                validEntity = true;
            }
            else
            {
                validEntity = false;
            }
        }

        void Contact::save()
        {
            personDetail.save();

            core::Sql sql(mDatabase);
            sql.var("personDetail", personDetail.id);

            sql.query("INSERT INTO contact(person_detail_id) VALUES(:personDetail)");
            sql.execute();

            id = var2Str(mDatabase.getLastInsertId());
        }

        void Contact::update()
        {
            personDetail.update();

            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("personDetail", personDetail.id);

            sql.query("UPDATE contact SET person_detail_id = :personDetail WHERE id = :id");
            sql.execute();
        }

        void Contact::destroy()
        {
            core::Sql sql(mDatabase);

            sql.var("id", id);
            sql.var("personDetail", personDetail.id);

            sql.query("DELETE FROM contact WHERE id = :id");
            sql.execute();
            sql.query("DELETE FROM person_detail WHERE id = :personDetail");
            sql.execute();
        }

        Contact& Contact::operator=(const Contact& contact)
        {
            id = contact.id;
            password = contact.password;
            personDetail = contact.personDetail;
            validEntity = contact.validEntity;
            mDatabase = contact.mDatabase;

            return *this;
        }

        Contact::~Contact()
        {

        }
    }

/*\
 | ------------------------------------------------------
 | @file : Admin.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représtant la table admin
 | ------------------------------------------------------
\*/

#include "Admin.hpp"

    namespace entity
    {
        Admin::Admin(core::Database& database) :
        Person::Person(database)
        {

        }

        void Admin::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            dataMap data;
            id = key;

            sql.var("id", id);
            sql.query("SELECT * FROM admin WHERE id = :id");
            data = sql.fetch();

            if(data.size() == 1)
            {
                password = data["0"]["password"];
                personDetail.hydrate(data["0"]["person_detail_id"]);
                validEntity = true;
            }
        }

        void Admin::save()
        {
            personDetail.save();

            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("password", password);
            sql.var("personDetail", personDetail.id);

            sql.query("INSERT INTO admin(id, password, person_detail_id) VALUES(:id, :password, :personDetail)");
            sql.execute();
        }

        void Admin::update()
        {
            personDetail.update();

            core::Sql sql(mDatabase);
            sql.var("id", id);
            sql.var("password", password);
            sql.var("personDetail", personDetail.id);

            sql.query("UPDATE admin SET password = :password, personDetail = :personDetail WHERE id = :id");
            sql.execute();
        }

        void Admin::destroy()
        {
            core::Sql sql(mDatabase);

            sql.var("id", id);
            sql.var("personDetail", personDetail.id);

            sql.query("DELETE FROM admin WHERE id = :id");
            sql.execute();
            sql.query("DELETE FROM person_detail WHERE id = :personDetail");
            sql.execute();
        }

        Admin& Admin::operator=(const Admin& admin)
        {
            id = admin.id;
            password = admin.password;
            personDetail = admin.personDetail;
            validEntity = admin.validEntity;
            mDatabase = admin.mDatabase;

            return *this;
        }

        Admin::~Admin()
        {

        }
    }

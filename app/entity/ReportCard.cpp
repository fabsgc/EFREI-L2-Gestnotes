/*\
 | ------------------------------------------------------
 | @file : ReportCard.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représantant la table report_card
 | ------------------------------------------------------
\*/

#include "ReportCard.hpp"

    namespace entity
    {
        ReportCard::ReportCard(core::Database& database) :
        Entity::Entity(database),
        student(database)
        {

        }

        void ReportCard::hydrate(std::string key)
        {
            core::Sql sql(mDatabase);
            stringMap data;
            dataMap   datas;

            id = std::stoi(key);

            sql.var("id", id);
            sql.query("SELECT * FROM report_card WHERE id = :id");
            datas = sql.fetch();

            if(datas.size() == 1)
            {
                data = datas["0"];
                sql.var("student", data["student_id"]);
                sql.query("SELECT * FROM student WHERE id = :student");
                datas = sql.fetch();

                if(datas.size() == 1)
                {
                    student.hydrate(datas["0"]["id"]);
                }

                validEntity = true;
            }
        }

        void ReportCard::save()
        {
            core::Sql sql(mDatabase);

            sql.var("student", student.id);
            sql.query("INSERT INTO report_card(student_id) VALUES(:student)");
            sql.execute();

            id = mDatabase.getLastInsertId();
        }

        void ReportCard::update()
        {
            core::Sql sql(mDatabase);

            sql.var("id", id);
            sql.var("student", student.id);
            sql.query("UPDATE report_card SET student_id = :student WHERE id = :id");
            sql.execute();
        }

        void ReportCard::destroy()
        {
            core::Sql sql(mDatabase);

            sql.var("id", id);
            sql.query("DELETE FROM report_card WHERE id = :id");
            sql.execute();
        }

        ReportCard& ReportCard::operator=(const ReportCard& reportCard)
        {
            student = reportCard.student;
            validEntity = reportCard.validEntity;
            return *this;
        }

        ReportCard::~ReportCard()
        {

        }
    }

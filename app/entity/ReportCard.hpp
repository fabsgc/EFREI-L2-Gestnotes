/*\
 | ------------------------------------------------------
 | @file : ReportCard.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Entité représantant la table report_card
 | ------------------------------------------------------
\*/

#ifndef REPORTCARD_HPP_INCLUDED
#define REPORTCARD_HPP_INCLUDED

#include "Student.hpp"

    namespace entity
    {
        class ReportCard : public core::Entity
        {
            public :
                     ReportCard(core::Database& mDatabase);
                     ~ReportCard();
                void hydrate(std::string key);
                void save();
                void update();
                void destroy();
                ReportCard& operator=(const ReportCard& reportCard);

            public :
                int id;
                Student student; //unique
        };
    }

#endif // REPORTCARD_HPP_INCLUDED

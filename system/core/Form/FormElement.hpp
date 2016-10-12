/*\
 | ------------------------------------------------------
 | @file : FormElement.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Représentation des champs que l'on peut valider avec leur contraintes respectives
 | ------------------------------------------------------
\*/

#ifndef FORMELEMENT_HPP_INCLUDED
#define FORMELEMENT_HPP_INCLUDED

#include "../../include.hpp"
#include "../Sql/Sql.hpp"

    namespace core
    {
        namespace form
        {
            enum Type {
                input          = 0,
                select         = 1,
                selectMultiple = 2,
                radio          = 3,
                checkbox       = 4
            };

            enum Contraint{
                different    = 0,
                equalTo      = 1,
                moreThan     = 2,
                lessThan     = 3,
                between      = 4,
                in           = 5,
                on           = 6,
                off          = 7,
                sizeMin      = 8,
                sizeMax      = 9,
                sizeExact    = 10,
                sizeBetween  = 11,
                sizeIn       = 12,
                countMin     = 13,
                countMax     = 14,
                countExact   = 15,
                countBetween = 16,
                countIn      = 17,
                email        = 18,
                match        = 19,
                sql          = 20
            };

            struct Element{
                form::Contraint contraint;
                std::string label;
                std::string contraintValue;
                std::string contraintError;
            };
        }

        class FormElement
        {
            public :
                             FormElement(Request & request, Database & database, form::Type type, std::string name);
                             ~FormElement();
                void         add(std::string label, form::Contraint contraint, std::string contraintValue, std::string contraintError);
                bool         check();
                stringVector getErrors();

            protected :
                bool         checkInputSelectRadio(const form::Element & element);
                bool         checkSelectMultiple(const form::Element & element);
                bool         checkCheckbox(const form::Element & element);

            protected :
                Request&                   mRequest;
                Database&                  mDatabase;
                form::Type                 mType;
                std::string                mName;
                stringVector               mErrors;
                std::vector<form::Element> mContraints;
        };
    }

#endif // FORMELEMENT_HPP_INCLUDED

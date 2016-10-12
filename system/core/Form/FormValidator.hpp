/*\
 | ------------------------------------------------------
 | @file : FormValidator.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Validateur de formulaire
 | ------------------------------------------------------
\*/

#ifndef FORMVALIDATOR_HPP_INCLUDED
#define FORMVALIDATOR_HPP_INCLUDED

#include "../../include.hpp"
#include "FormElement.hpp"

    namespace core
    {
        class FormValidator
        {
            public :
                           FormValidator(Request & request, Database & database);
                           ~FormValidator();
                void       add(std::string name, std::string label, form::Type type, form::Contraint contraint, std::string contraintValue, std::string contraintError);
                bool       sent();
                bool       check();
                dataVector getErrors();

            private :
                std::string                        mToken;
                Request&                           mRequest;
                Database&                          mDatabase;
                dataVector                         mErrors;
                std::map<std::string, FormElement> mElements;
        };
    }

#endif // FORMVALIDATOR_HPP_INCLUDED

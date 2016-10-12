/*\
 | ------------------------------------------------------
 | @file : FormValidator.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Validateur de formulaire
 | ------------------------------------------------------
\*/

#include "FormValidator.hpp"

    namespace core
    {
        FormValidator::FormValidator(Request & request, Database & database) :
        mRequest(request),
        mDatabase(database)
        {
        }

        void FormValidator::add(std::string name, std::string label, form::Type type, form::Contraint contraint, std::string contraintValue, std::string contraintError)
        {
            if(!isset(mElements, name))
            {
                FormElement element(mRequest, mDatabase, type, name);
                element.add(label, contraint, contraintValue, contraintError);
                mElements.insert(std::pair<std::string,FormElement>(name,element));
            }
            else
            {
                FormElement & element = mElements.find(name)->second;
                element.add(label, contraint, contraintValue, contraintError);
            }
        }

        bool FormValidator::sent()
        {
            if(var2Str(getenv("REQUEST_METHOD")) == "POST")
            {
                return true;
            }

            return false;
        }

        bool FormValidator::check()
        {
            bool valid = true;

            for(auto i = mElements.begin(); i != mElements.end(); i++)
            {
                if(i->second.check() == false)
                {
                    mErrors[i->first] = i->second.getErrors();
                    valid = false;
                }
            }

            return valid;
        }

        dataVector FormValidator::getErrors()
        {
            return mErrors;
        }

        FormValidator::~FormValidator()
        {

        }
    }

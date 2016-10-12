/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityContact.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Contact est une entité représentant la table contact
 | ------------------------------------------------------
\*/

#include "TemplateContainerEntityContact.hpp"

    namespace core
    {
        TemplateContainerEntityContact::TemplateContainerEntityContact(std::string name, const entity::Contact & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerEntityContact::render() const
        {
            std::string result = "$" + mName + " = array(); \n";

            result += "$" + mName + "['id'] = " + var2Str(mValue.id) + "; \n";
            
            return result;
        }

        stringVector TemplateContainerEntityContact::renderChild() const
        {
            stringVector data;
            std::string result;

            result = "['" + mName + "'] = array(); \n";
            data.push_back(result);

            {
                TemplateContainerString t("id", mValue.id);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerEntityPersonDetail t("personDetail", mValue.personDetail);
                stringVector v = t.renderChild();

                for(auto i = v.begin(); i != v.end(); i++)
                {
                    result = "['" + mName + "']" + *i;
                    data.push_back(result);
                }
            }

            return data;
        }

        TemplateContainerEntityContact::~TemplateContainerEntityContact()
        {

        }
    }

/*\
 | ------------------------------------------------------
 | @file : TemplateContainerEntityPersonDetail.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : PersonDetail est une entité représentant la table person_detail
 | ------------------------------------------------------
\*/

#include "TemplateContainerEntityPersonDetail.hpp"

    namespace core
    {
        TemplateContainerEntityPersonDetail::TemplateContainerEntityPersonDetail(std::string name, const entity::PersonDetail & value) :
        mName(name),
        mValue(value)
        {

        }

        std::string TemplateContainerEntityPersonDetail::render() const
        {
            std::string result = "$" + mName + " = array(); \n";

            {
                TemplateContainerInt t("id", mValue.id);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("name", mValue.name);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("firstName", mValue.firstName);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("address", mValue.address);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("city", mValue.city);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("postalCode", mValue.postalCode);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("country", mValue.country);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("email", mValue.email);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("avatar", mValue.avatar);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("phoneHome", mValue.phoneHome);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("phoneMobile", mValue.phoneMobile);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("dateBorn", mValue.dateBorn);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerString t("dateRegister", mValue.dateRegister);
                result += "$" + mName + t.renderChild().front();
            }

            {
                TemplateContainerInt t("gender", mValue.gender);
                result += "$" + mName + t.renderChild().front();
            }

            return result;
        }

        stringVector TemplateContainerEntityPersonDetail::renderChild() const
        {
            stringVector data;
            std::string result;

            result = "['" + mName + "'] = array(); \n";
            data.push_back(result);

            {
                TemplateContainerInt t("id", mValue.id);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("name", mValue.name);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("firstName", mValue.firstName);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("address", mValue.address);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("city", mValue.city);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("postalCode", mValue.postalCode);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("country", mValue.country);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("email", mValue.email);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("avatar", mValue.avatar);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("phoneHome", mValue.phoneHome);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("phoneMobile", mValue.phoneMobile);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("dateBorn", mValue.dateBorn);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerString t("dateRegister", mValue.dateRegister);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            {
                TemplateContainerInt t("gender", mValue.gender);
                result = "['" + mName + "']" + t.renderChild().front();
                data.push_back(result);
            }

            return data;
        }

        TemplateContainerEntityPersonDetail::~TemplateContainerEntityPersonDetail()
        {

        }
    }

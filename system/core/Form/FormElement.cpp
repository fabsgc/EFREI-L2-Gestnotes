/*\
 | ------------------------------------------------------
 | @file : FormElement.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Représentation des champs que l'on peut valider avec leur contraintes respectives
 | ------------------------------------------------------
\*/

#include "FormElement.hpp"

    namespace core
    {
        FormElement::FormElement(Request & request, Database & database, form::Type type, std::string name) :
        mRequest(request),
        mDatabase(database),
        mType(type),
        mName(name)
        {

        }

        void FormElement::add(std::string label, form::Contraint contraint, std::string contraintValue, std::string contraintError)
        {
            form::Element element;
            element.label = label;
            element.contraint = contraint;
            element.contraintValue = contraintValue;
            element.contraintError = contraintError;
            mContraints.push_back(element);
        }

        bool FormElement::check()
        {
            bool valid = true;

            for(auto i = mContraints.begin(); i != mContraints.end(); i++)
            {
                switch(mType)
                {
                    case form::Type::input :
                        if(!checkInputSelectRadio(*i))
                        {
                            valid = false;
                            mErrors.push_back(i->label + " : " + i->contraintError);
                        }
                    break;

                    case form::Type::select :
                        if(!checkInputSelectRadio(*i))
                        {
                            valid = false;
                            mErrors.push_back(i->label + " : " + i->contraintError);
                        }
                    break;

                    case form::Type::selectMultiple :
                        if(!checkSelectMultiple(*i))
                        {
                            valid = false;
                            mErrors.push_back(i->label + " : " + i->contraintError);
                        }
                    break;

                    case form::Type::radio :
                        if(!checkInputSelectRadio(*i))
                        {
                            valid = false;
                            mErrors.push_back(i->label + " : " + i->contraintError);
                        }
                    break;

                    case form::Type::checkbox :
                        if(!checkCheckbox(*i))
                        {
                            valid = false;
                            mErrors.push_back(i->label + " : " + i->contraintError);
                        }
                    break;
                }
            }

            return valid;
        }

        bool FormElement::checkInputSelectRadio(const form::Element & element)
        {
            bool valid = true;
            std::vector<std::string> values = splitString(element.contraintValue, "-");
            std::regex regNumber("^([0-9+])(\\.*)([0-9+]*)$");
            std::regex regMail("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,6}$");
            std::regex regMatch(element.contraintValue);
            std::regex regSql("\\[(.+)\\]\\[(.+)\\]\\[(.+)\\]");
            std::string query;
            std::string queryContraint;
            int queryContraintValue;
            Sql sql(mDatabase);

            switch(element.contraint)
            {
                case form::Contraint::different :
                    if(mRequest.post(mName) == element.contraintValue)
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::equalTo :
                    if(mRequest.post(mName) != element.contraintValue)
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::moreThan :
                    if(std::regex_match (mRequest.post(mName), regNumber))
                    {
                        if(stof(mRequest.post(mName)) < stof(element.contraintValue))
                        {
                            valid = false;
                        }
                    }
                    else
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::lessThan :
                    if(std::regex_match (mRequest.post(mName), regNumber))
                    {
                        if(stof(mRequest.post(mName)) > stof(element.contraintValue))
                        {
                            valid = false;
                        }
                    }
                    else
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::between :
                    if(std::regex_match (mRequest.post(mName), regNumber))
                    {
                        if(stof(mRequest.post(mName)) < stof(values.front()) || stof(mRequest.post(mName)) > stof(values.back()))
                        {
                            valid = false;
                        }
                    }
                    else
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::in :
                    values = splitString(element.contraintValue, "-");

                    if(!isset(values, mRequest.post(mName)))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::sizeMin :
                    if(mRequest.post(mName).size() < std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::sizeMax :
                    if(mRequest.post(mName).size() > std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::sizeExact :
                    if(mRequest.post(mName).size() != std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::sizeBetween :
                    if(mRequest.post(mName).size() < std::stoul(values.front().c_str()) || mRequest.post(mName).size() > std::stoul(values.front().c_str()))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::sizeIn :
                    values = splitString(element.contraintValue, "-");

                    if(!isset(values, var2Str(mRequest.post(mName).size())))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::email :
                    if(!std::regex_match (mRequest.post(mName), regMail))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::match :
                    if(!std::regex_match (mRequest.post(mName), regMatch))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::sql :
                    query = std::regex_replace(element.contraintValue, regSql, "$1");
                    queryContraint = std::regex_replace(element.contraintValue, regSql, "$2");
                    queryContraintValue = std::stoul(std::regex_replace(element.contraintValue, regSql, "$3"));

                    sql.query(query);
                    sql.var("input", mRequest.post(mName));

                    if(queryContraint == "==")
                    {
                        if(sql.fetch().size() != queryContraintValue)
                            valid = false;
                    }
                    else if(queryContraint == ">")
                    {
                        if(sql.fetch().size() <= queryContraintValue)
                            valid = false;
                    }
                    else if(queryContraint == "<")
                    {
                        if(sql.fetch().size() >= queryContraintValue)
                            valid = false;
                    }
                    else if(queryContraint == ">=")
                    {
                        if(sql.fetch().size() < queryContraintValue)
                            valid = false;
                    }
                    else if(queryContraint == "<=")
                    {
                        if(sql.fetch().size() > queryContraintValue)
                            valid = false;
                    }
                    else if(queryContraint == "!=")
                    {
                        if(sql.fetch().size() == queryContraintValue)
                            valid = false;
                    }
                break;

                default :
                    valid = false;
                break;
            }

            return valid;
        }

        bool FormElement::checkSelectMultiple(const form::Element & element)
        {
            bool valid = true;
            std::vector<std::string> inputs = splitString(mRequest.post(mName), "-");
            std::vector<std::string> values = splitString(element.contraintValue, "-");
            std::regex regSql("\\[(.+)\\]\\[(.+)\\]\\[(.+)\\]");
            std::string query;
            std::string queryContraint;
            int queryContraintValue;
            Sql sql(mDatabase);

            switch(element.contraint)
            {
                case form::Contraint::different :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(isset(values, *i))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::equalTo :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(!isset(values, *i))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::lessThan :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(*i != "")
                        {
                            float input = stof(*i);

                            if(input > stof(values[0]))
                            {
                                valid = false;
                                break;
                            }
                        }
                        else
                        {
                            valid = false;
                        }
                    }
                break;

                case form::Contraint::moreThan :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(*i != "")
                        {
                            float input = stof(*i);

                            if(input < stof(values[0]))
                            {
                                valid = false;
                                break;
                            }
                        }
                        else
                        {
                            valid = false;
                        }
                    }
                break;

                case form::Contraint::between :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(*i != "")
                        {
                            float input = stof(*i);

                            if(input < stof(values.front()) || input > stof(values.back()))
                            {
                                valid = false;
                                break;
                            }
                        }
                        else
                        {
                            valid = false;
                        }
                    }
                break;

                case form::Contraint::in :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(!isset(values, *i))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeMin :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(i->size() < std::stoul(element.contraintValue))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeMax :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(i->size() > std::stoul(element.contraintValue))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeExact :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(i->size() != std::stoul(element.contraintValue))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeBetween :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(i->size() < std::stoul(values.front().c_str()) || i->size() > std::stoul(values.back().c_str()))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeIn :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(!isset(values, var2Str(i->size())))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::countMin :
                    if(inputs.size() < std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::countMax :
                    if(inputs.size() > std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::countExact :
                    if(inputs.size() != std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::countBetween :
                    if(inputs.size() < std::stoul(values.front().c_str()) || inputs.size() > std::stoul(values.back().c_str()))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::countIn :
                    if(!isset(values, var2Str(inputs.size())))
                    {
                        valid = false;
                        break;
                    }
                break;

                case form::Contraint::sql :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        query = std::regex_replace(element.contraintValue, regSql, "$1");
                        queryContraint = std::regex_replace(element.contraintValue, regSql, "$2");
                        queryContraintValue = std::stoul(std::regex_replace(element.contraintValue, regSql, "$3"));

                        sql.query(query);
                        sql.var("input", *i);

                        if(queryContraint == "==")
                        {
                            if(sql.fetch().size() != queryContraintValue)
                                valid = false;
                        }
                        else if(queryContraint == ">")
                        {
                            if(sql.fetch().size() <= queryContraintValue)
                                valid = false;
                        }
                        else if(queryContraint == "<")
                        {
                            if(sql.fetch().size() >= queryContraintValue)
                                valid = false;
                        }
                        else if(queryContraint == ">=")
                        {
                            if(sql.fetch().size() < queryContraintValue)
                                valid = false;
                        }
                        else if(queryContraint == "<=")
                        {
                            if(sql.fetch().size() > queryContraintValue)
                                valid = false;
                        }
                        else if(queryContraint == "!=")
                        {
                            if(sql.fetch().size() == queryContraintValue)
                                valid = false;
                        }
                    }
                break;

                default :
                    valid = false;
                break;
            }

            return valid;
        }

        bool FormElement::checkCheckbox(const form::Element & element)
        {
            std::vector<std::string> inputs = splitString(mRequest.post(mName), "-");
            std::vector<std::string> values = splitString(element.contraintValue, "-");

            bool valid = true;

            switch(element.contraint)
            {
                case form::Contraint::on :
                    if(inputs.size() > 0)
                    {
                        return false;
                    }
                break;

                case form::Contraint::off :
                    if(inputs.size() == 0)
                    {
                        return false;
                    }
                break;

                case form::Contraint::different :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(isset(values, *i))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::equalTo :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(!isset(values, *i))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::lessThan :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(*i != "")
                        {
                            float input = stof(*i);

                            if(input > stof(values[0]))
                            {
                                valid = false;
                                break;
                            }
                        }
                        else
                        {
                            valid = false;
                        }
                    }
                break;

                case form::Contraint::moreThan :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(*i != "")
                        {
                            float input = stof(*i);

                            if(input < stof(values[0]))
                            {
                                valid = false;
                                break;
                            }
                        }
                        else
                        {
                            valid = false;
                        }
                    }
                break;

                case form::Contraint::between :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(*i != "")
                        {
                            float input = stof(*i);

                            if(input < stof(values.front()) || input > stof(values.back()))
                            {
                                valid = false;
                                break;
                            }
                        }
                        else
                        {
                            valid = false;
                        }
                    }
                break;

                case form::Contraint::in :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(!isset(values, *i))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeMin :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(i->size() < std::stoul(element.contraintValue))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeMax :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(i->size() > std::stoul(element.contraintValue))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeExact :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(i->size() != std::stoul(element.contraintValue))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeBetween :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(i->size() < std::stoul(values.front().c_str()) || i->size() > std::stoul(values.back().c_str()))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::sizeIn :
                    for(auto i = inputs.begin(); i != inputs.end(); i++)
                    {
                        if(!isset(values, var2Str(i->size())))
                        {
                            valid = false;
                            break;
                        }
                    }
                break;

                case form::Contraint::countMin :
                    if(inputs.size() < std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::countMax :
                    if(inputs.size() > std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::countExact :
                    if(inputs.size() != std::stoul(element.contraintValue))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::countBetween :
                    if(inputs.size() < std::stoul(values.front().c_str()) || inputs.size() > std::stoul(values.back().c_str()))
                    {
                        valid = false;
                    }
                break;

                case form::Contraint::countIn :
                    if(!isset(values, var2Str(inputs.size())))
                    {
                        valid = false;
                        break;
                    }
                break;

                default :
                    valid = false;
                break;
            }

            return valid;
        }

        stringVector FormElement::getErrors()
        {
            return mErrors;
        }

        FormElement::~FormElement()
        {

        }
    }

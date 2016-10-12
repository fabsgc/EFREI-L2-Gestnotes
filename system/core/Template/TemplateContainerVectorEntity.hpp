/*\
 | ------------------------------------------------------
 | @file : TemplateContainerVectorEntity.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : Permet de passer aux templates une liste d'entités
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINERVECTORENTITY_HPP_INCLUDED
#define TEMPLATECONTAINERVECTORENTITY_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../function.hpp"
#include "TemplateContainer.hpp"

    namespace core
    {
        template<typename T>
        class TemplateContainerVectorEntity : public TemplateContainer
        {
            public :
                TemplateContainerVectorEntity(std::string name, const std::vector<T> & value) :
                mName(name),
                mValue(value)
                {

                }

                ~TemplateContainerVectorEntity()
                {

                }

                std::string render() const
                {
                    std::string result = "$" + mName + " = array(); \n";
                    int k = 0;

                    for(auto i = mValue.begin(); i!= mValue.end(); i++)
                    {
                        stringVector v = (*i).renderChild();

                        for(auto j = v.begin(); j != v.end(); j++)
                        {
                            result += "$" + mName + *j;
                        }

                        k++;
                    }

                    return result;
                }

                stringVector renderChild() const
                {
                    stringVector data;
                    std::string result;
                    int k = 0;

                    for(auto i = mValue.begin(); i!= mValue.end(); i++)
                    {
                        stringVector v = (*i).renderChild();

                        for(auto j = v.begin(); j != v.end(); j++)
                        {
                            result = "['" + mName + "']" + *j;
                            data.push_back(result);
                        }

                        k++;
                    }

                    return data;
                }

            private :
                std::string    mName;
                std::vector<T> mValue;
        };
    }

#endif // TEMPLATECONTAINERVECTORENTITY_HPP_INCLUDED

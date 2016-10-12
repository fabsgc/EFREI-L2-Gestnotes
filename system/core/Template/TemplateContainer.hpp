/*\
 | ------------------------------------------------------
 | @file : TemplateContainer.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : template container permet de faire passer des données typées provenant du code C++ vers la vue qui est en html/php
 | ------------------------------------------------------
\*/

#ifndef TEMPLATECONTAINER_HPP_INCLUDED
#define TEMPLATECONTAINER_HPP_INCLUDED

#include <iostream>
#include <string>
#include "../../../function.hpp"

    namespace core
    {
        class TemplateContainer
        {
            public :
                        TemplateContainer();
                virtual ~TemplateContainer();
                virtual std::string  render() const = 0;
                virtual stringVector renderChild() const = 0;
        };
    }

#endif // TEMPLATECONTAINER_HPP_INCLUDED

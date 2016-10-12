#ifndef APP_INCLUDE_HPP_INCLUDED
#define APP_INCLUDE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include <winsock.h>
#include <MYSQL/mysql.h>

const std::string USER_ADMIN   = "ADMIN";
const std::string USER_TEACHER = "TEACHER";
const std::string USER_STUDENT = "STUDENT";

#include "../system/core/Session/Session.hpp"
#include "../system/core/Config/Config.hpp"
#include "../system/core/Request/Request.hpp"
#include "../system/core/Database/Database.hpp"
#include "../system/core/Sql/Sql.hpp"
#include "../system/core/Template/Template.hpp"
#include "../system/core/Template/TemplateContainer.hpp"
#include "../system/core/Controller/Controller.hpp"
#include "../system/core/Model/Model.hpp"
#include "../system/core/Entity/Entity.hpp"
#include "../system/core/Form/FormValidator.hpp"
#include "../function.hpp"

std::string detectUserType(std::string username);

#endif // APP_INCLUDE_INCLUDED

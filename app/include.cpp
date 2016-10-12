#include "include.hpp"

std::string detectUserType(std::string username)
{
    std::regex regAdmin("^(admin)(.+)$");
    std::regex regTeacher("^(teacher)(.+)$");

    if(std::regex_match (username, regAdmin))
    {
        return USER_ADMIN;
    }
    else if(std::regex_match (username, regTeacher))
    {
        return USER_TEACHER;
    }

    return USER_STUDENT;
}

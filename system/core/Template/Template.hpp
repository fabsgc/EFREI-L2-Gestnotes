/*\
 | ------------------------------------------------------
 | @file : Template.cpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : moteur de template du framework
 | ------------------------------------------------------
\*/

#ifndef TEMPLATE_HPP_INCLUDED
#define TEMPLATE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>
#include "../Config/Config.hpp"
#include "../Request/Request.hpp"
#include "../Session/Session.hpp"
#include "../Url/Url.hpp"
#include "TemplateContainer.hpp"
#include "TemplateContainerDataMap.hpp"
#include "TemplateContainerDataVector.hpp"
#include "TemplateContainerInt.hpp"
#include "TemplateContainerBool.hpp"
#include "TemplateContainerString.hpp"
#include "TemplateContainerStringMap.hpp"
#include "TemplateContainerEntityAdmin.hpp"
#include "TemplateContainerEntityContact.hpp"
#include "TemplateContainerEntityCourse.hpp"
#include "TemplateContainerEntityGroup.hpp"
#include "TemplateContainerEntityMark.hpp"
#include "TemplateContainerEntityPersonDetail.hpp"
#include "TemplateContainerEntityReportCard.hpp"
#include "TemplateContainerEntityStudent.hpp"
#include "TemplateContainerEntityTeacher.hpp"
#include "TemplateContainerVectorEntity.hpp"

    const std::string TEMPLATE_PATH       = "app/template/";
    const std::string TEMPLATE_CACHE_PATH = "app/cache/template/";

    namespace core
    {
        class Template
        {
            public :
                            Template(std::string path, std::string name, Config &config, Request &request);
                            ~Template();
                void        var(const std::string & name, int value);
                void        var(const std::string & name, bool value);
                void        var(const std::string & name, const std::string & value);
                void        var(const std::string & name, const char * value);
                void        var(const std::string & name, const dataMap & value);
                void        var(const std::string & name, const dataVector & value);
                void        var(const std::string & name, const stringMap & value);
                void        var(const std::string & name, const entity::Admin & value);
                void        var(const std::string & name, const entity::Contact & value);
                void        var(const std::string & name, const entity::Course & value);
                void        var(const std::string & name, const entity::Group & value);
                void        var(const std::string & name, const entity::Mark & value);
                void        var(const std::string & name, const entity::PersonDetail & value);
                void        var(const std::string & name, const entity::ReportCard & value);
                void        var(const std::string & name, const entity::Student & value);
                void        var(const std::string & name, const entity::Teacher & value);
                void        var(const std::string & name, const std::vector<std::string> & value);
                void        var(const std::string & name, const std::vector<entity::Admin> & value);
                void        var(const std::string & name, const std::vector<entity::Contact> & value);
                void        var(const std::string & name, const std::vector<entity::Course> & value);
                void        var(const std::string & name, const std::vector<entity::Group> & value);
                void        var(const std::string & name, const std::vector<entity::Mark> & value);
                void        var(const std::string & name, const std::vector<entity::PersonDetail> & value);
                void        var(const std::string & name, const std::vector<entity::ReportCard> & value);
                void        var(const std::string & name, const std::vector<entity::Student> & value);
                void        var(const std::string & name, const std::vector<entity::Teacher> & value);
                std::string getPhp();
                std::string render();

            protected :
                void        compile(bool vars = true);
                std::string getSession() const;
                std::string parseVars(std::string content) const;
                std::string parseIf(std::string content) const;
                std::string parseForeach(std::string content) const;
                std::string parseUrl(std::string content) const;
                std::string parseDefine(std::string content) const;
                std::string parseInclude(std::string content) const;
                std::string parseSession(std::string content);

            protected :
                Config&     mConfig;
                Request&    mRequest;
                Session     mSession;
                Url         mUrl;

                std::string mPath;
                std::string mName;
                std::string mContent;

                std::vector<TemplateContainerDataMap>                                           mVarsDataMap;
                std::vector<TemplateContainerDataVector>                                        mVarsDataVector;
                std::vector<TemplateContainerInt>                                               mVarsInt;
                std::vector<TemplateContainerBool>                                              mVarsBool;
                std::vector<TemplateContainerString>                                            mVarsString;
                std::vector<TemplateContainerStringMap>                                         mVarsStringMap;
                std::vector<TemplateContainerEntityAdmin>                                       mVarsEntityAdmin;
                std::vector<TemplateContainerEntityContact>                                     mVarsEntityContact;
                std::vector<TemplateContainerEntityCourse>                                      mVarsEntityCourse;
                std::vector<TemplateContainerEntityGroup>                                       mVarsEntityGroup;
                std::vector<TemplateContainerEntityMark>                                        mVarsEntityMark;
                std::vector<TemplateContainerEntityPersonDetail>                                mVarsEntityPersonDetail;
                std::vector<TemplateContainerEntityReportCard>                                  mVarsEntityReportCard;
                std::vector<TemplateContainerEntityStudent>                                     mVarsEntityStudent;
                std::vector<TemplateContainerEntityTeacher>                                     mVarsEntityTeacher;
                std::vector<TemplateContainerVectorEntity<TemplateContainerString>>             mVarsVectorString;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityAdmin>>        mVarsVectorEntityAdmin;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityContact>>      mVarsVectorEntityContact;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityCourse>>       mVarsVectorEntityCourse;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityGroup>>        mVarsVectorEntityGroup;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityMark>>         mVarsVectorEntityMark;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityPersonDetail>> mVarsVectorEntityPersonDetail;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityReportCard>>   mVarsVectorEntityReportCard;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityStudent>>      mVarsVectorEntityStudent;
                std::vector<TemplateContainerVectorEntity<TemplateContainerEntityTeacher>>      mVarsVectorEntityTeacher;
        };
    }

#endif // TEMPLATE_HPP_INCLUDED

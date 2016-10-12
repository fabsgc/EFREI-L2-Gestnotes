/*\
 | ------------------------------------------------------
 | @file : Template.hpp
 | @author : Fabien Beaujean, Luc Lorentz
 | @description : moteur de template du framework
 | ------------------------------------------------------
\*/

#include "Template.hpp"

    namespace core
    {
        Template::Template(std::string path, std::string name, Config &config, Request &request) :
        mConfig(config),
        mRequest(request),
        mUrl(config)
        {
            mPath    = TEMPLATE_PATH + path + ".tpl";
            mName    = name;
            mContent = fileGetContent(mPath);

            mSession.setCookie(mRequest.cookie());

            var("session", mSession.all());
            var("cookie", mRequest.cookie());
            var("get", mRequest.get());
            var("post", mRequest.post());
            var("define", mConfig.getDefine());
            var("request", mRequest.getRoute().getAll());
        }

        void Template::var(const std::string & name, int value)
        {
            TemplateContainerInt var(name, value);
            mVarsInt.push_back(var);
        }

        void Template::var(const std::string & name, bool value)
        {
            TemplateContainerBool var(name, value);
            mVarsBool.push_back(var);
        }

        void Template::var(const std::string & name, const std::string & value)
        {
            TemplateContainerString var(name, value);
            mVarsString.push_back(var);
        }

        void Template::var(const std::string & name, const char * value)
        {
            TemplateContainerString var(name, var2Str(value));
            mVarsString.push_back(var);
        }

        void Template::var(const std::string & name, const dataMap & value)
        {
            TemplateContainerDataMap var(name, value);
            mVarsDataMap.push_back(var);
        }

        void Template::var(const std::string & name, const dataVector & value)
        {
            TemplateContainerDataVector var(name, value);
            mVarsDataVector.push_back(var);
        }

        void Template::var(const std::string & name, const stringMap & value)
        {
            TemplateContainerStringMap var(name, value);
            mVarsStringMap.push_back(var);
        }

        void Template::var(const std::string & name, const entity::Admin & value)
        {
            TemplateContainerEntityAdmin var(name, value);
            mVarsEntityAdmin.push_back(var);
        }

        void Template::var(const std::string & name, const entity::Contact & value)
        {
            TemplateContainerEntityContact var(name, value);
            mVarsEntityContact.push_back(var);
        }

        void Template::var(const std::string & name, const entity::Course & value)
        {
            TemplateContainerEntityCourse var(name, value);
            mVarsEntityCourse.push_back(var);
        }

        void Template::var(const std::string & name, const entity::Group & value)
        {
            TemplateContainerEntityGroup var(name, value);
            mVarsEntityGroup.push_back(var);
        }

        void Template::var(const std::string & name, const entity::Mark & value)
        {
            TemplateContainerEntityMark var(name, value);
            mVarsEntityMark.push_back(var);
        }

        void Template::var(const std::string & name, const entity::PersonDetail & value)
        {
            TemplateContainerEntityPersonDetail var(name, value);
            mVarsEntityPersonDetail.push_back(var);
        }

        void Template::var(const std::string & name, const entity::ReportCard & value)
        {
            TemplateContainerEntityReportCard var(name, value);
            mVarsEntityReportCard.push_back(var);
        }

        void Template::var(const std::string & name, const entity::Student & value)
        {
            TemplateContainerEntityStudent var(name, value);
            mVarsEntityStudent.push_back(var);
        }

        void Template::var(const std::string & name, const entity::Teacher & value)
        {
            TemplateContainerEntityTeacher var(name, value);
            mVarsEntityTeacher.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<std::string> & value)
        {
            std::vector<TemplateContainerString> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerString var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerString> var(name, data);
            mVarsVectorString.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::Admin> & value)
        {
            std::vector<TemplateContainerEntityAdmin> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityAdmin var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityAdmin> var(name, data);
            mVarsVectorEntityAdmin.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::Contact> & value)
        {
            std::vector<TemplateContainerEntityContact> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityContact var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityContact> var(name, data);
            mVarsVectorEntityContact.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::Course> & value)
        {
            std::vector<TemplateContainerEntityCourse> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityCourse var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityCourse> var(name, data);
            mVarsVectorEntityCourse.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::Group> & value)
        {
            std::vector<TemplateContainerEntityGroup> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityGroup var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityGroup> var(name, data);
            mVarsVectorEntityGroup.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::Mark> & value)
        {
            std::vector<TemplateContainerEntityMark> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityMark var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityMark> var(name, data);
            mVarsVectorEntityMark.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::PersonDetail> & value)
        {
            std::vector<TemplateContainerEntityPersonDetail> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityPersonDetail var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityPersonDetail> var(name, data);
            mVarsVectorEntityPersonDetail.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::ReportCard> & value)
        {
            std::vector<TemplateContainerEntityReportCard> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityReportCard var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityReportCard> var(name, data);
            mVarsVectorEntityReportCard.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::Student> & value)
        {
            std::vector<TemplateContainerEntityStudent> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityStudent var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityStudent> var(name, data);
            mVarsVectorEntityStudent.push_back(var);
        }

        void Template::var(const std::string & name, const std::vector<entity::Teacher> & value)
        {
            std::vector<TemplateContainerEntityTeacher> data;
            int j = 0;

            for(auto i = value.begin(); i != value.end(); i++)
            {
                TemplateContainerEntityTeacher var(var2Str(j), *i);
                data.push_back(var);
                j++;
            }

            TemplateContainerVectorEntity<TemplateContainerEntityTeacher> var(name, data);
            mVarsVectorEntityTeacher.push_back(var);
        }

        void Template::compile(bool vars)
        {
            std::string renderPhp = "<?php\n";

            if(vars == true)
            {
                for(auto i = mVarsStringMap.begin(); i != mVarsStringMap.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsInt.begin(); i != mVarsInt.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsBool.begin(); i != mVarsBool.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsString.begin(); i != mVarsString.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsDataMap.begin(); i != mVarsDataMap.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsDataVector.begin(); i != mVarsDataVector.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityAdmin.begin(); i != mVarsEntityAdmin.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityContact.begin(); i != mVarsEntityContact.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityCourse.begin(); i != mVarsEntityCourse.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityGroup.begin(); i != mVarsEntityGroup.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityMark.begin(); i != mVarsEntityMark.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityPersonDetail.begin(); i != mVarsEntityPersonDetail.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityReportCard.begin(); i != mVarsEntityReportCard.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityStudent.begin(); i != mVarsEntityStudent.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsEntityTeacher.begin(); i != mVarsEntityTeacher.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorString.begin(); i != mVarsVectorString.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityAdmin.begin(); i != mVarsVectorEntityAdmin.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityContact.begin(); i != mVarsVectorEntityContact.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityCourse.begin(); i != mVarsVectorEntityCourse.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityGroup.begin(); i != mVarsVectorEntityGroup.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityMark.begin(); i != mVarsVectorEntityMark.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityPersonDetail.begin(); i != mVarsVectorEntityPersonDetail.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityReportCard.begin(); i != mVarsVectorEntityReportCard.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityStudent.begin(); i != mVarsVectorEntityStudent.end(); i++)
                {
                    renderPhp += i->render();
                }

                for(auto i = mVarsVectorEntityTeacher.begin(); i != mVarsVectorEntityTeacher.end(); i++)
                {
                    renderPhp += i->render();
                }
            }

            renderPhp += "?>";

            renderPhp += mContent;
            renderPhp = parseDefine(renderPhp);
            renderPhp = parseIf(renderPhp);
            renderPhp = parseForeach(renderPhp);
            renderPhp = parseUrl(renderPhp);
            renderPhp = parseInclude(renderPhp);
            renderPhp = parseVars(renderPhp);
            renderPhp = parseSession(renderPhp);

            filePutContent(TEMPLATE_CACHE_PATH + mName + ".php", renderPhp);
        }

        std::string Template::render()
        {
            compile();
            std::string parsing = "C:\\wamp\\bin\\php\\php5.5.12\\php.exe " + TEMPLATE_CACHE_PATH + mName + ".php" + " > " + TEMPLATE_CACHE_PATH + mName + ".php.compiled";
            system(parsing.c_str());
            return fileGetContent(TEMPLATE_CACHE_PATH + mName + ".php.compiled");
        }

        std::string Template::getPhp()
        {
            compile(false);
            return fileGetContent(TEMPLATE_CACHE_PATH + mName + ".php");
        }

        std::string Template::parseVars(std::string content) const
        {
            std::regex regVar ("\\{(\\$)([\\[\\]\\(\\)A-Za-z0-9\\$'._>\\+-]+)\\}");

            content = std::regex_replace (content, regVar, "<?php echo $1$2; ?>");

            return content;
        }

        std::string Template::parseIf(std::string content) const
        {
            std::regex regIfBegin ("<if condition=\"(.*)\">");
            std::regex regIfEnd   ("</if>");
            std::regex regElseIf  ("<elseif condition=\"(.*)>\"");
            std::regex regElse    ("<else/>");

            content = std::regex_replace (content, regIfBegin, "<?php if($1){ ?>");
            content = std::regex_replace (content, regIfEnd, "<?php } ?>");
            content = std::regex_replace (content, regElseIf, "<?php } elseif ($1) { ?>");
            content = std::regex_replace (content, regElse, "<?php } else { ?>");

            return content;
        }

        std::string Template::parseForeach(std::string content) const
        {
            std::regex regForeachBegin ("<foreach loop=\"(.*)\">");
            std::regex regForeachEnd ("</foreach>");

            content = std::regex_replace (content, regForeachBegin, "<?php foreach($1){ ?>");
            content = std::regex_replace (content, regForeachEnd, "<?php } ?>");

            return content;
        }

        std::string Template::parseDefine(std::string content) const
        {
            std::string contentMatch = content;
            std::smatch m;
            std::regex regInclude ("\\{\\{define:(.*)\\}\\}");

            while(std::regex_search (contentMatch,m,regInclude))
            {
                for(auto x:m)
                {
                    if(isset(mConfig.getAuth(), var2Str(x)))
                    {
                        std::string include = mConfig.getAuth()[x];
                        std::regex regReplaceInclude("(\\{\\{define:" + var2Str(x) + "\\}\\})");
                        content = std::regex_replace (content, regReplaceInclude, include);
                    }
                }

                contentMatch = m.suffix().str();
            }

            return content;
        }

        std::string Template::parseInclude(std::string content) const
        {
            std::regex regInclude ("<include src=\"(.*)\"\\/>");
            std::string contentMatch = content;
            std::smatch m;

            while(std::regex_search (contentMatch,m,regInclude))
            {
                for(auto x:m)
                {
                    Template tpl(x, mName + "_include_" + replaceBy(x, "/", "_") , mConfig, mRequest);
                    std::string include = tpl.getPhp();

                    std::regex regReplaceInclude("(<include src=\"" + replaceBy(x, "/", "\\/") + "\"\\/>)");
                    content = std::regex_replace (content, regReplaceInclude, include);
                }

                contentMatch = m.suffix().str();
            }

            return content;
        }

        std::string Template::parseSession(std::string content)
        {
            std::regex regFlashMessage ("<clear:flash\\/>");
            std::string contentMatch = content;
            std::smatch m;

            while(std::regex_search (contentMatch,m,regFlashMessage))
            {
                content = std::regex_replace (content, regFlashMessage, "");
                mSession.removeFlash();
                break;
            }

            return content;
        }

        std::string Template::parseUrl(std::string content) const
        {
            return content;
        }

        Template::~Template()
        {

        }
    }

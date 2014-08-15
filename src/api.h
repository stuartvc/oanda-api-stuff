#pragma once
#include <string>
#include <map>
#include <json/json.h>



class API {
protected:
    API(std::string baseURL/*, std::string authToken*/);
    ~API();

    Json::Value get(std::string endpoint, std::map<std::string, std::string> queryParams);
    Json::Value post(std::string endpoint, std::map<std::string, std::string> bodyParams);
    //JSONNod patch(std::string endpoint, std::map<std::string, std::string> bodyParams);
    //JSONNod head(std::string endpoint, std::map<std::string, std::string> bodyParams);

private:
    std::string formatQueryString(std::map<std::string, std::string> queryString);
    std::string baseURL_;
    //std::string authToken_;
    //bool authEnabled_;

};

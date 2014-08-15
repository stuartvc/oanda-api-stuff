#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

#include <iostream>
#include "api.h"

using namespace Poco;
using namespace Poco::Net;

API::API(std::string baseURL/*, std::string authToken*/)
{
    baseURL_ = baseURL;
    //authToken_ = authToken;
}

API::~API()
{

}

Json::Value API::get(std::string endpoint, std::map<std::string, std::string> queryParams)
{
    std::string queryString = formatQueryString(queryParams);
    Json::Value jsonNode;

    try 
    {
        URI uri(baseURL_ + endpoint + "?" + queryString);

        HTTPClientSession session(uri.getHost(), uri.getPort());

        // prepare path
        std::string path(uri.getPathAndQuery());
        if (path.empty()) path = "/";

        HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
        req.set("X-Accept-Datetime-Format", "Unix");
        //req.set("Authorization", std::string("Bearer ") + access_token);

        session.sendRequest(req);

        // get response
        HTTPResponse res;
        std::istream &rs = session.receiveResponse(res);

        Json::Reader reader;

        reader.parse(rs, jsonNode);


    }
    catch (...)
    {

    }
    //return std::string("hi");
    //return rs.str();
    return jsonNode;

}

Json::Value API::post(std::string endpoint, std::map<std::string, std::string> bodyParams)
{
    return std::string("hi");

}

std::string API::formatQueryString(std::map<std::string, std::string> queryParams)
{
    std::string queryString;
    for (std::map<std::string, std::string>::iterator param=queryParams.begin(); param!=queryParams.end(); ++param)
    {
        queryString += param->first + "=" + param->second + "&";
    }

    return queryString.substr(0, queryString.length()-1);
}

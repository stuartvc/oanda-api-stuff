#include "instruments.h"
#include <boost/lexical_cast.hpp>
#include <iostream>

Instruments::Instruments() : API("http://api-sandbox.oanda.com")
{
    params_["accountId"] = "1094425";
}
Instruments::~Instruments()
{
}

std::vector<std::string> Instruments::getInstruments()
{
    Json::Value response = get("/v1/instruments", params_);

    //std::cout << response << std::endl;

    std::vector<std::string> instrumentsVec;

    for (Json::Value::iterator it=response["instruments"].begin();
            it!=response["instruments"].end();
            ++it)
    {
        instrumentsVec.push_back((*it)["instrument"].asString());
    }


    return instrumentsVec;
}

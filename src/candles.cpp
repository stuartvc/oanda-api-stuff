#include "candles.h"
#include <boost/lexical_cast.hpp>

CandleStick::CandleStick(int time, double open, double high, double low, double close, int volume) : time(time), 
    open(open), 
    high(high), 
    low(low), 
    close(close), 
    volume(volume) 
{
}

Candles::Candles(std::string instrument) : API("http://api-sandbox.oanda.com")
{
    params_["instrument"] = instrument;
    params_["count"] = "5000";
    params_["granularity"] = "H2";
}
Candles::~Candles()
{

}

void Candles::setParams(int count, std::string newInstrument, std::string granularity)
{
    params_["instrument"] = newInstrument;
    params_["count"] = count;
    params_["granularity"] = granularity;
}

std::vector<CandleStick> Candles::getCandles(std::vector<CandleStick>& candlesVec)
{
    Json::Value response = get("/v1/candles", params_);

    for (Json::Value::iterator it=response["candles"].begin();
            it!=response["candles"].end();
            ++it)
    {
        candlesVec.push_back(CandleStick(
                    boost::lexical_cast<int> ((*it)["time"].asString().substr(0,10)), 
                    (*it)["openAsk"].asDouble(), 
                    (*it)["highAsk"].asDouble(), 
                    (*it)["lowAsk"].asDouble(), 
                    (*it)["closeAsk"].asDouble(), 
                    (*it)["volume"].asDouble()));
    }


    return candlesVec;
}

std::vector<CandleStick> Candles::getCandles()
{
    Json::Value response = get("/v1/candles", params_);

    std::vector<CandleStick> candlesVec;

    for (Json::Value::iterator it=response["candles"].begin();
            it!=response["candles"].end();
            ++it)
    {
        candlesVec.push_back(CandleStick(
                    boost::lexical_cast<int> ((*it)["time"].asString().substr(0,10)), 
                    (*it)["openAsk"].asDouble(), 
                    (*it)["highAsk"].asDouble(), 
                    (*it)["lowAsk"].asDouble(), 
                    (*it)["closeAsk"].asDouble(), 
                    (*it)["volume"].asDouble()));
    }


    return candlesVec;
}

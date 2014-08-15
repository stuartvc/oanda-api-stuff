#pragma once
#include <json/json.h>
#include "api.h"

struct CandleStick
{
    CandleStick();
    CandleStick(int time, double open, double high, double low, double close, int volume);
    int time;
    double open;
    double high;
    double low;
    double close;
    int volume;
};


class Candles : public API
{
    public:
    Candles(std::string instrument);
    ~Candles();

    std::vector<CandleStick> getCandles();
    void setParams(int count, std::string newInstrument, std::string granularity);
    std::vector<CandleStick> getCandles(std::vector<CandleStick>& candlesVec);

    private:
    std::map<std::string, std::string> params_;


};

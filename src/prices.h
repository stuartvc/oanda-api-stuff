#pragma once
#include <json/json.h>
#include "api.h"

struct Tick
{
    Tick(double ask, double bid) : ask(ask), bid(bid){}
    Tick(){}
    double ask;
    double bid;
};


class Prices : public API
{
    public:
    Prices(std::string instrument);
    ~Prices();

    Tick getPrice();

    private:
    std::map<std::string, std::string> params_;


};

#include "prices.h"

Prices::Prices(std::string instrument) : API("http://api-sandbox.oanda.com")
{
    params_["instruments"] = instrument;
}
Prices::~Prices()
{

}

/*std::map<std::string, double> Prices::getPrice()
{
    Json::Value response = get("/v1/prices", params_);

    std::map<std::string, double> prices;

    prices["bid"] = response["prices"][0]["bid"].asDouble();
    prices["ask"] = response["prices"][0]["ask"].asDouble();

    return prices;
}*/

Tick Prices::getPrice()
{
    Json::Value response = get("/v1/prices", params_);

    Tick price(response["prices"][0]["bid"].asDouble(), response["prices"][0]["ask"].asDouble());

    return price;
}

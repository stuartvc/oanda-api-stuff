#pragma once
#include <json/json.h>
#include <string>
#include <vector>
#include "api.h"

struct Order
{
    Order();
    Order(int id, int time, std::string instrument, int price);
    std::vector<std::string> toVec();
    int id;
    int time;
    std::string instrument;
    int price;
};

class Orders : public API
{
    public:
    Orders(std::string instrument);
    ~Orders();

    bool postOrder();
    Order getOrder();

    private:
    std::map<std::string, std::string> params_;


};

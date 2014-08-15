#pragma once
#include <json/json.h>
#include "api.h"

class Instruments : public API
{
    public:
    Instruments();
    ~Instruments();

    std::vector<std::string> getInstruments();

    private:
    std::map<std::string, std::string> params_;


};

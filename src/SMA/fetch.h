#include "../candles.h"
#include <vector>
#include <iostream>
#include "redispp.h"

class FetchSMA
{
    public:
        FetchSMA();
        ~FetchSMA();

        void fetchSMA(std::vector<double>& avg, std::string gran, int period, int number);

    private:
        redispp::Connection redis;
};

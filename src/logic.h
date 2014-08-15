#include <iostream>
#include "prices.h"
#include "candles.h"


class Logic
{
    public:
        Logic();
        ~Logic();

        void run();

    private:

        Prices prices;
        Candles candles;
        std::vector<std::string> granularities;
        std::vector<std::string> instruments;
};

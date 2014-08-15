#include "../candles.h"
#include <vector>
#include <iostream>

class CachedSMA
{
    public:
        CachedSMA();
        CachedSMA(int count);
        ~CachedSMA();

        void loadCandles();
        void calculateSMA();

    private:
        std::vector<std::vector<double> > SMA;
        std::vector<CandleStick> candles;
        int count;
        std::string instrument;
        std::string granularity;
        Candles API;
};

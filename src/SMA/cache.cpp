#include "cache.h"
#include <boost/lexical_cast.hpp>
#include "redispp.h"

CachedSMA::CachedSMA(): API(instrument)
{ 
    CachedSMA(50);
}
CachedSMA::CachedSMA(int count): count(count),
    instrument("EUR_USD"),
    granularity("D"),
    API(instrument)
{}
CachedSMA::~CachedSMA()
{}

void CachedSMA::loadCandles()
{
    candles = API.getCandles(candles);
}

void CachedSMA::calculateSMA()
{
    redispp::Connection redis("127.0.0.1","6379", "password", false);
    double* buffer;
    int index = 0;
        std::vector<double> temp;
        SMA.push_back(temp);
        SMA.push_back(temp);
    for (int i = 2; i < 50; i++)
    {
        index = 0;
        buffer = new double[i]();
        std::vector<double> temp;
        SMA.push_back(temp);
        for (std::vector<CandleStick>::iterator it = candles.begin();
                it != candles.end();
                ++it, index++)
        {
            buffer[index%i] = it->close/i;
            double sum = 0;
            for (int j = 0; j < i; j++)
            {
                sum+=buffer[j];
            }
            sum*=100000;
            int sumInt = sum;
            redis.rpush("sma-EUR_USD-D-" + boost::lexical_cast<std::string>(i), boost::lexical_cast<std::string>(sumInt));
            SMA[i].push_back(sum);
        }
        delete [] buffer;
    }
    std::cout << "done" << std::endl;
}

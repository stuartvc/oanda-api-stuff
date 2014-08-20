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
    std::vector<std::string> gran;
    gran.push_back("S5");
    gran.push_back("S10");
    gran.push_back("S15");
    gran.push_back("S30");
    gran.push_back("M1");
    gran.push_back("M2");
    gran.push_back("M3");
    gran.push_back("M5");
    gran.push_back("M10");
    gran.push_back("M15");
    gran.push_back("M30");
    gran.push_back("H1");
    gran.push_back("H2");
    gran.push_back("H3");
    gran.push_back("H4");
    gran.push_back("H6");
    gran.push_back("H8");
    gran.push_back("H12");
    gran.push_back("D");
    gran.push_back("W");
    gran.push_back("M");
    redispp::Connection redis("127.0.0.1","6379", "password", false);
    double* buffer;
    int index = 0;
    for (std::vector<std::string>::iterator granu=gran.begin();
            granu!=gran.end();
            ++granu)
    {
        for (int i = 2; i < 50; i++)
        {
            index = 0;
            double sum=0;
            buffer = new double[i]();
            for (std::vector<CandleStick>::iterator it = candles.begin();
                    it != candles.end();
                    ++it, index++)
            {
                sum+=it->close;
                if (index>=i-1)
                {
                    int avg = (sum/i)*100000;
                    redis.rpush("sma-EUR_USD-"+(*granu)+"-" + boost::lexical_cast<std::string>(i), boost::lexical_cast<std::string>(avg));
                    sum-=candles[index-i+1].close;
                }

                /*buffer[index%i] = it->close/i;
                double sum = 0;
                for (int j = 0; j < i; j++)
                {
                    sum+=buffer[j];
                }
                sum*=100000;
                int sumInt = sum;
                redis.rpush("sma-EUR_USD-D-" + boost::lexical_cast<std::string>(i), boost::lexical_cast<std::string>(sumInt));*/
            }
            delete [] buffer;
        }
    }
    std::cout << "done" << std::endl;
}

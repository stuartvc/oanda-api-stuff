#include "logic.h"
#include <vector>
#include <map>
#include <string>
#include <redispp.h>
#include "SMA/cache.h"
#include "SMA/fetch.h"

Logic::Logic() : prices("EUR_USD"), candles("EUR_USD")
{
    granularities.push_back("S5");
    granularities.push_back("S10");
    granularities.push_back("S15");
    granularities.push_back("S30");
    granularities.push_back("M1");
    granularities.push_back("M2");
    granularities.push_back("M3");
    granularities.push_back("M5");
    granularities.push_back("M10");
    granularities.push_back("M15");
    granularities.push_back("M30");
    granularities.push_back("H1");
    granularities.push_back("H2");
    granularities.push_back("H3");
    granularities.push_back("H4");
    granularities.push_back("H6");
    granularities.push_back("H8");
    granularities.push_back("H12");
    granularities.push_back("D");
    granularities.push_back("W");
    granularities.push_back("M");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
    instruments.push_back("EUR_USD");
}

Logic::~Logic()
{
}

void Logic::run()
{

    FetchSMA fetch;

    std::vector<double> avg;
    fetch.fetchSMA(avg, "D", 12, 500);

    for (int i = 0; i <10; i++)
    {
        std::cout << avg[i] << std::endl;
    }

    avg.clear();
    std::cout << "cleared" << std::endl;

    fetch.fetchSMA(avg, "D", 45, 500);

    for (int i = 0; i <10; i++)
    {
        std::cout << avg[i] << std::endl;
    }



    //std::vector<double* > candlesVec;
    //redispp::Connection redis("127.0.0.1","6379", "password", false);

    //CachedSMA cacher(500);

    //cacher.loadCandles();

    //cacher.calculateSMA();

    /*for (std::vector<std::string>::iterator it1=instruments.begin();
            it1!=instruments.end();
            ++it1)
    {
        for (std::vector<std::string>::iterator it=granularities.begin();
                it!=granularities.end();
                ++it)
        {
            for (int i = 0; i < 100; i++)
            {
                //candles.setParams(5000, *it, *it1);
                double *newVec = new double[5000];
                //candles.getCandles(newVec);
                candlesVec.push_back(newVec);
            }
        }
    }
    std::cout << candlesVec.size() << std::endl;
    std::cout << sizeof(double) << std::endl;*/

    //sleep(50);


    /*Tick oldPrice = prices.getPrice();
    Tick newPrice;
    while(true)
    {
        newPrice = prices.getPrice();

        if (newPrice.ask > oldPrice.ask)
        {
            std::cout << "buy" << std::endl;
            //buy
        }
        else
        {
            std::cout << "sell" << std::endl;
            //sell
        }
        oldPrice = newPrice;
        sleep(5);
    }*/
    std::cout << "done" << std::endl;
}

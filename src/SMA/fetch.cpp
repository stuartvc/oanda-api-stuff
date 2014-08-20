#include "fetch.h"
#include "redispp.h"
#include <boost/lexical_cast.hpp>

FetchSMA::FetchSMA(): redis("127.0.0.1","6379", "password", false)
{

}
FetchSMA::~FetchSMA()
{

}

void FetchSMA::fetchSMA(std::vector<double>& avg, std::string gran, int period, int number)
{
    std::string key = "sma-EUR_USD-"+gran+"-"+boost::lexical_cast<std::string>(period);
    redispp::MultiBulkEnumerator response = redis.lrange(key, 0, number);
    std::string avg_S;
    while (response.next(&avg_S))
    {
        avg.push_back(boost::lexical_cast<double>(avg_S)/100000);
    }

}

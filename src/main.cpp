#include <iostream>
#include <string>
#include <map>
#include "prices.h"
#include "candles.h"
#include "instruments.h"
#include "logic.h"


int main(){

    /*Prices EUR_USD("EUR_USD");

    Tick price = EUR_USD.getPrice();
    std::cout << price.bid << " " << price.ask << std::endl;

    Candles EUR("EUR_USD");

    std::vector<CandleStick> candles = EUR.getCandles();
    std::cout << candles[0].time << std::endl;
    std::cout << candles[0].open << std::endl;
    std::cout << candles[0].high << std::endl;
    std::cout << candles[0].volume << std::endl;
    std::cout << candles.size() << std::endl;

    Instruments All;

    std::vector<std::string> instruments = All.getInstruments();

    std::cout << instruments[0] << std::endl;*/


    Logic runner;

    runner.run();

    return 0;
}

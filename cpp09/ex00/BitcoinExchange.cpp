#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {...}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {}

void BitcoinExchange::loadDatabase(const std::string &databaseFile) {
    std::ifstream file(fileName.c_str()); 
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open database.");
        return 1;
    }
    while (std::getline(file, line)) {
        std::string date;
        double rate;

        if (parseCsvLine(line, date, rate)) {
            _rates[date] = rate;
        }
    }
}

void BitcoinExchange::processInput(const std::string &inputFile) {

}

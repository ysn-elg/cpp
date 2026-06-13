#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, double> _dataBase;
    

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange &operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string &databaseFile);
    void processInput(const std::string &inputFile);

private:
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, double& value) const;

    double getExchangeRate(const std::string& date) const;

    std::string trim(const std::string& str) const;
};

#endif

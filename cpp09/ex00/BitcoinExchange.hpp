#ifndef   BITCOINEXCHANGE_HPP
# define  BITCOINEXCHANGE_HPP

class BitcoinExchange {
private:

    bool parseCsvLine(std::string& line, std::string& date, std::string& rate);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange &operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string &databaseFile);
    void processInput(const std::string &inputFile);
}

#endif

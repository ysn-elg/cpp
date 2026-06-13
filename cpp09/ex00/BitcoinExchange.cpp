#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _dataBase(other._dataBase) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _dataBase = other._dataBase;
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string &databaseFile) {
    std::ifstream file(databaseFile.c_str()); 
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::size_t pos = line.find('.');
        if (pos != std::string::npos) {
            std::string date = line.substr(0, pos);
            double rate = std::atof(line.substr(pos + 1).c_str());
            _dataBase[date] = rate;
        }
    }
}

void BitcoinExchange::processInput(const std::string &inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::size_t pos = line.find(" | ");
        if (pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, pos));
        std::string valStr = trim(line.substr(pos + 3));
        
        double value;
        
        if (!isValidDate(date))
            std::cerr << "Error: bad input => " << date << std::endl;
        else if (!isValidValue(valStr, value))
            continue;
        else {
            double rate = getExchangeRate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
    }
}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return (first == std::string::npos) ? "" : str.substr(first, (last - first + 1));
}
// ------------------------

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length()!= 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year)) {
        return day <= 29;
    }
    return day <= daysInMonth[month];

    return true;
}

#include "BitcoinExchange.hpp"


int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./btc <file>";
        return 1;
    }
    try {
        BitcoinExchange btc;
        btc.loadDatabase("data.csv");
        btc.processInput(argv[1]);
    }
    catch() {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}


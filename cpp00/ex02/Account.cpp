#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// static getters
int Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

Account::Account( void ) {}

void  Account::_displayTimestamp( void ) { // should I change it to current date
    std::cout << "[19920104_091532] ";
}

Account::Account( int initial_deposit )
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

// Destructor
Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}


void    Account::makeDeposit( int deposit )
{
    int previousAmount = _amount;

    _amount += deposit; 
    _nbDeposits++;
    _totalAmount += deposit;
    ++_totalNbDeposits;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << previousAmount
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    int previousAmount = _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << previousAmount;
    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return true;
}

int     Account::checkAmount( void ) const { return _amount; }

void    Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl ;
}


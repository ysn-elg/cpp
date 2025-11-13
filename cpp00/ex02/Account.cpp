#include "Account.hpp"

Account::Account( int initial_deposit )
    : _accountIndex(_nbAccounts),
      _amount(inial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
        
}

void    Account::makeDeposit( int deposit )
{
    _amount += deposit; // should we check if deposit < 0 ?
    _nbDeposite++;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    if (_amount < deposit)
    {
        std::cout << "****" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawal++;
    return true;
}

int     Account::checkAmount( void )        { return _amount; }

void    Account::displayStatus( void )
{
    _displaTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";deposit:" << _nbDeposits;
    std::cout << ";withdraw:" << _nbWithdrawals; << std::endl ;
}

//Global
int Account::getNbAccounts( void )      { return _accountIndex; }
int	Account::getTotalAmount( void )     { return _totalAmount; }
int	Account::getNbDeposits( void )      { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void )   { return _totalNbWithdrawals; }


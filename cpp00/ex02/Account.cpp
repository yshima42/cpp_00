#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
    _nbAccounts++;
    _totalAmount += _amount;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}

int Account::getNbAccounts( void ) { return (_nbAccounts); }
int Account::getTotalAmount( void ) { return (_totalAmount); }
int Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() 
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount;

    p_amount = _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << p_amount << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount;
    bool successWithdraw;

    p_amount = _amount;
    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
       successWithdraw = true; 
    }
    else
        successWithdraw = false;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << p_amount << ";";

    if (!successWithdraw)
        std::cout << "withdrawal:refused" << std::endl;
    else
    {
        std::cout << "withdrawal:" << withdrawal << ";"
                  << "amount:" << _amount << ";"
                  << "nb_withdrawals:" << _nbWithdrawals
                  << std::endl;
    }
    return (successWithdraw);
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"  
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals
              << std::endl;
}    

void	Account::_displayTimestamp( void )
{
    time_t now = std::time(NULL);
    const tm* local_time = localtime(&now);
    std::cout << std::put_time(local_time, "[%Y%m%d_%H%M%S] ");
}

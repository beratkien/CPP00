#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(NULL);
    std::tm* tm_info = std::localtime(&t);
    std::cout << "[" << tm_info->tm_year + 1900
                << std::setw(2) << std::setfill('0') << tm_info->tm_mon + 1
                << std::setw(2) << std::setfill('0') << tm_info->tm_mday << "_"
                << std::setw(2) << std::setfill('0') << tm_info->tm_hour
                << std::setw(2) << std::setfill('0') << tm_info->tm_min
                << std::setw(2) << std::setfill('0') << tm_info->tm_sec << "] ";

}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
                << "total:" << getTotalAmount() << ";"
                << "deposits:" << getNbDeposits() << ";"
                << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "closed" << std::endl;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::makeDeposit(int deposit)
{
    int curr_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << curr_amount << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << this->_amount << ";"
              << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";";
    if(withdrawal > this->_amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalAmount -= withdrawal;
    this->_totalNbWithdrawals++;

    std::cout << "withdrawal:" << withdrawal << ";"
              << "amount:" << this->_amount << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals << std::endl;
} 





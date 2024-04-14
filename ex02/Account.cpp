#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
	: _accountIndex(getNbAccounts())
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << initial_deposit << ";created\n";

	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount << ";closed\n";
	_nbAccounts--;
}

#define YYYYMMDD_HHMMSS 17

void Account::_displayTimestamp() {
	char   timestamp[YYYYMMDD_HHMMSS];
	time_t epoch = time(0);
	tm*    now   = localtime(&epoch);
	strftime(static_cast<char*>(timestamp), sizeof(timestamp),
			 "%Y%m%d_%H%M%S", now);
	std::cout << "[" << static_cast<char*>(timestamp) << "] ";
}

int Account::getTotalAmount() { return (_totalAmount); }

int Account::getNbDeposits() { return (_totalNbDeposits); }

int Account::getNbWithdrawals() { return (_totalNbWithdrawals); }

int Account::checkAmount() const { return (_amount); }

int Account::getNbAccounts() { return (_nbAccounts); }

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << checkAmount()
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	const int p_amount = checkAmount();
	if (withdrawal >= p_amount) {
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << p_amount
				  << ";withdrawal:refused\n";
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << checkAmount()
			  << ";nb_withdrawals:" << (++_nbWithdrawals)
			  << std::endl;
	_totalNbWithdrawals++;
	return true;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	const int p_amount = checkAmount();
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << checkAmount()
			  << ";nb_deposits:" << (++_nbDeposits) << std::endl;
	_totalNbDeposits++;
}

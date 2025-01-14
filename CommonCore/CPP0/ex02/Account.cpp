#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(void) {
	std::time_t	now = std::time(NULL);
	std::tm		*ltm = std::localtime(&now);
	char		buffer[20];

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);
	std::cout << buffer;
	//std::cout << "[19920104_091532] ";
}

Account::Account(int initial_deposit): _accountIndex(_nbAccounts++),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
}

Account::~Account(void) {
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	int p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
		<< ";deposit:" << deposit << ";amount:" << _amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = this->_amount;

	if (withdrawal > p_amount) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
			<< ";withdrawal:refused" << std::endl;
	}
	else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return false;
}

int Account::checkAmount(void) const { return 0; }

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

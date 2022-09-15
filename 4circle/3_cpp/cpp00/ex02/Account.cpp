#include <iostream>
#include "Account.hpp"

 int	Account::getNbAccounts() {
	return _nbAccounts;
 }

 int	Account::getTotalAmount() {
	return _totalAmount;
 }

 int	Account::getNbDeposits() {
	return _totalNbDeposits;
 }

 int	Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
 }

 Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
 }

 void	Account::displayAccountsInfos() {

 }
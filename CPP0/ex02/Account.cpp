/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:33:34 by marschul          #+#    #+#             */
/*   Updated: 2024/01/16 19:35:10 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() \
		<< ";total:" << Account::getTotalAmount() \
		<< ";deposits:" << Account::getNbDeposits() \
		<< ";withdrawals:" << Account::getNbWithdrawals() \
		<< std::endl;
}

Account::Account(void) {}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << std::to_string(_accountIndex) << ";amount:" << \
		std::to_string(_amount) << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << " index:" << std::to_string(_accountIndex) << ";amount:" << \
	std::to_string(_amount) << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_nbDeposits++;
	Account::_totalNbDeposits = Account::getNbDeposits() + 1;
	_amount += deposit;
	Account::_totalAmount = Account::getTotalAmount() + deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
		<< ";p_amount:" << _amount - deposit \
		<< ";deposit:" << deposit \
		<< ";amount:" << _amount \
		<< ";nb_deposits:" << _nbDeposits \
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	bool	refused = false;
	int		p_amount = _amount;
	std::string	str;

	if (checkAmount() - withdrawal < 0)
		refused = true;
	else
	{
		_amount -= withdrawal;
		Account::_totalAmount = Account::getTotalAmount() - withdrawal;
		_nbWithdrawals++;
		Account::_totalNbWithdrawals = Account::getNbWithdrawals() + 1;
	}

	if (refused)
		str = "refused";
	else
		str = std::to_string(withdrawal) + ";amount:" + std::to_string(_amount) + ";nb_withdrawals:" + std::to_string(_nbWithdrawals);
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
		<< ";p_amount:" << p_amount \
		<< ";withdrawal:" \
		<< str \
		<< std::endl;
	return refused;
}

int		Account::checkAmount(void) const {
	return _amount;
}

void	Account::_displayTimestamp(void) {
    char 		buffer[80];
    std::time_t currentTime = std::time(nullptr);
    std::tm* 	localTime = std::localtime(&currentTime);

    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
    std::cout << std::string(buffer);
};

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
		<< ";amount:" << _amount \
		<< ";deposits:" << _nbDeposits \
		<< ";withdrawals:" << _nbWithdrawals \
		<< std::endl;
}

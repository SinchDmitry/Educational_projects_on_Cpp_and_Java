/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchiba <aarchiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:35:53 by aarchiba          #+#    #+#             */
/*   Updated: 2022/05/18 17:58:15 by aarchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";" << \
	"total:" << Account::getTotalAmount() << ";" << \
	"deposits:" << Account::getNbDeposits() << ";" << \
	"withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) {
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
	<< "amount:" << this->_amount << ";" << "created" << std::endl;

}

Account::Account( void ) {
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
	<< "amount:0" << ";" << "created" << std::endl;
}

Account::~Account( void ) {
	this->_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
	<< "amount:" << this->_amount << ";" << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	this->_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";" \
	<< "p_amount:" << this->_amount << ";" << "deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";" << "nb_deposits:" \
	<< this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
	<< "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount) {
		std::cout << "refised" << std::endl;
		return false;
	}
	else {
		this->_totalAmount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "amount:" << this->_amount << "nb_withdrawals:" \
		<< this->_nbWithdrawals << std::endl;
		return true;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
	<< "amount:" << this->_amount << ";" \
	<< "deposits:" << this->_nbDeposits << ";" \
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t	online = time(NULL);
	tm		*timeinfo = localtime(&online);
	std::cout << std::setfill('0') << "[" << timeinfo->tm_year + 1900 << \
	std::setw(2) << timeinfo->tm_mon + 1 << \
	std::setw(2) <<timeinfo->tm_mday << "_" << \
	std::setw(2) <<timeinfo->tm_hour << \
	std::setw(2) <<timeinfo->tm_min << \
	std::setw(2) <<timeinfo->tm_sec << "]";
}

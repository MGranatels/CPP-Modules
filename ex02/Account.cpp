/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:18:14 by bcarreir          #+#    #+#             */
/*   Updated: 2023/03/25 15:31:35 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	static int	i;

	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = 0;
	this->_accountIndex = i++;
	this->_nbAccounts = i;
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" \
		<< this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int	Account::getTotalAmount( void )
{
	int	amount;
	
	amount = 8;
	return(amount);
}

// int	Account::getNbDeposits( void )
// {
	
// }
// int	Account::getNbWithdrawals( void )
// {
	
// }

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
			  << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" 
			  << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
			  << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals ++;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount 
			  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const
{
	return 1;
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
			  << this->_amount << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{

	time_t now = time(0);
	tm *time = localtime(&now);

	std::cout << "[" << 1900 + time->tm_year;
	if (time->tm_mon < 9)
		std::cout << "0";
	std::cout << 1 + time->tm_mon << time->tm_mday;
	std::cout << "_" << time->tm_hour << time->tm_min << time->tm_sec << "] ";
}

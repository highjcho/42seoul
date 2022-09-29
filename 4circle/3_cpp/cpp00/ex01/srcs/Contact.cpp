/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:13:28 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/09/29 12:50:33 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	return ;
}

Contact::Contact(std::string _firstName, std::string _lastName, std::string _nickname, std::string _phoneNumber, std::string _darkestSecret) {
	this->_firstName = _firstName;
	this->_lastName = _lastName;
	this->_nickname = _nickname;
	this->_phoneNumber = _phoneNumber;
	this->_darkestSecret = _darkestSecret;
}

std::string Contact::truncate(std::string info) {
	if (info.length() > MAX_WIDTH)
		return (info.substr(0, MAX_WIDTH - 1) + ".");
	return (info);
}

void	Contact::displayAllInfo() {
	std::cout << "[1] First Name: " << _firstName << std::endl;
	std::cout << "[2] Last Name: " << _lastName << std::endl;
	std::cout << "[3] Nickname: " << _nickname << std::endl;
	std::cout << "[4] Phone Number: " << _phoneNumber << std::endl;
	std::cout << "[5] Darkest Secret: " << _darkestSecret << std::endl;
}

void	Contact::displayShortInfo(int idx) {
	std::cout << std::setw(MAX_WIDTH) << idx << "| " << std::setw(MAX_WIDTH) << truncate(_firstName) << "| " \
		<< std::setw(MAX_WIDTH) << truncate(_lastName) << "| " << std::setw(MAX_WIDTH) << truncate(_nickname) << std::endl;
}

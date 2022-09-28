/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:13:23 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/09/28 19:22:03 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

# define MAX_WIDTH 10

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		Contact(std::string _firstName, std::string _lastName, std::string _nickname, \
			std::string _phoneNumber, std::string _darkestSecret);
		std::string	truncate(std::string info);
		void	displayAllInfo();
		void	displayShortInfo(int idx);
};

#endif
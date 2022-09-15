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
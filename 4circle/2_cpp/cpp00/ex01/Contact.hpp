#include <string>

class Contact {
	private:
		int			idx;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_darkest_secret;

	public:
		Contact(int index, std::string _first_name, std::string _last_name, \
			std::string _nick_name, std::string _phone_number, std::string _darkest_secret);
		
}
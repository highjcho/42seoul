/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:43:53 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/28 18:20:19 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMETERIA_HPP

#include <iostream>

# define AMATERIA	"\033[0;32m"
# define ICE		"\033[1;33m"
# define CURE		"\033[1;36m"
# define CHARACTER	"\033[0;35m"
# define EOC		"\033[0;0m"

class ICharacter;

class AMateria {
	protected:
		std::string name;
		std::string type;

	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria &obj);
		AMateria& operator=(const AMateria &obj);
		virtual ~AMateria();

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
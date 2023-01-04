/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:51:10 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/04 12:36:25 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

# define ANIMAL	"\033[0;32m"
# define DOG	"\033[1;33m"
# define CAT	"\033[1;36m"
# define EOC	"\033[0;0m"

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &obj);
		Animal& operator=(const Animal &obj);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
};

#endif
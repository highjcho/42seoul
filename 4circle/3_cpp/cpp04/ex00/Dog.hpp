/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DOg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:44:40 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 16:09:27 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(const Dog &obj);
		Dog& operator=(const Dog &obj);
		~Dog();

		void makeSound() const;
		std::string getType() const;
};

#endif
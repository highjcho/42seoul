/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:44:40 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/04 12:36:42 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog &obj);
		Dog& operator=(const Dog &obj);
		~Dog();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif
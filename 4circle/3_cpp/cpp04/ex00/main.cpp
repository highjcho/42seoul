/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:51:41 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 16:41:42 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const Animal* meta = new Animal();
	std::cout << CAT << "\n" << i->getType() << "\n\n";
	std::cout << DOG << j->getType() << "\n\n";
	std::cout << ANIMAL << meta->getType() << "\n\n";
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	const WrongAnimal* w = new WrongCat();
	std::cout << CAT << w->getType() << "\n\n";
	w->makeSound();
	delete w;
	return 0;
}
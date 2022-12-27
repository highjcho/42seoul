/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:51:41 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 18:43:56 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// Animal* animal = new Animal();
	Animal* animal = new Cat();
	Dog* dog = new Dog();
	Cat* cat = new Cat();

	std::cout << ANIMAL << animal->getType() << EOC << "\n\n";

	dog->getBrain()->setIdea("제 이름은 절미입니다.\n\n");
	cat->getBrain()->setIdea("제 이름은 무입니다.\n\n");

	std::cout << DOG << dog->getBrain()->getIdea(0);
	std::cout << CAT << cat->getBrain()->getIdea(0) << EOC;

	delete dog;
	delete cat;

	return 0;
}
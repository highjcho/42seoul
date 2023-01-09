/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:51:41 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 19:09:54 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Animal* animals[4];
	int i;
	std::string ideas[8] = {"밥먹자", "산책가자", "잘래", "내 이름은 뭐야", "어디가", "신난다", "빨리와", "보고싶어"};

	for (i = 0; i < 4; i++) {
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n=====================================================\n\n";
	Dog* dog = new Dog();
	srand(time(NULL));
	for (i = 0; i < 5; i++) {
		int num = rand() % 8;
		dog->getBrain()->setIdea(ideas[num]);
	}
	std::cout << DOG << "요즘 내가 하는 생각은 말야! ";
	for (i = 0; i < 5; i++) {
		std::cout << dog->getBrain()->getIdea(i);
		if (i != 4)
			std::cout << ", ";
	}
	std::cout << EOC << "\n\n";

	delete dog;
	return 0;
}
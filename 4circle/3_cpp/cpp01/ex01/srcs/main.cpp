/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:56:14 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:40:47 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie* zombies;
	int	cnt;

	std::cout << "How many zombies do you want to create? ==> ";
	std::cin >> cnt;
	zombies = Zombie::zombieHorde(cnt, "zombie");
	delete[] zombies;
	return (0);
}
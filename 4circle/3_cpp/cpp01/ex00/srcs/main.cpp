/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:31 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:34:14 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie zombieA = Zombie("stackZombieA");
	zombieA.announce();

	Zombie* zombieB = Zombie::newZombie("heapZombieB");
	zombieB->announce();

	Zombie::randomChump("stackRandomChumpZombieC");

	delete zombieB;
}
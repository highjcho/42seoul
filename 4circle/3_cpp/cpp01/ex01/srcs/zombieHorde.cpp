/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:56:22 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:41:13 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde(const int N, const std::string name) {
	Zombie* zombies = new Zombie[N];
	std::stringstream idx;

	for (int i = 0; i < N; i++) {
		idx << i;
		zombies[i].setName(name + idx.str());
		zombies[i].announce();
		idx.str("");
	}
	return zombies;
}
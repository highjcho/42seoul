/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/19 13:36:44 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap* mu = new ClapTrap("Mu");
	ClapTrap* samsak = new ClapTrap("Samsak");
	ClapTrap* yatong = new ClapTrap("Yatong");

	while (mu->getEnergy()) {
		mu->attack("Samsak");
		samsak->takeDamage(mu->getAttackDamage());
	}
	mu->attack("Samsak");
	samsak->attack("Yatong");
	yatong->takeDamage(samsak->getAttackDamage());
	samsak->beRepaired(10);
	delete samsak;
	delete yatong;
}
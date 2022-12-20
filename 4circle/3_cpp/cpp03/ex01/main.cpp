/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/20 12:14:07 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap* mu = new ScavTrap("Mu");
	ScavTrap* samsak = new ScavTrap("Samsak");
	ClapTrap* yatong = new ClapTrap("Yatong");
	ClapTrap* dodo = new ClapTrap("Dodo");

	mu->attack("Samsak");
	samsak->takeDamage(mu->getAttackDamage());
	mu->attack("Samsak");
	samsak->attack("Yatong");
	yatong->takeDamage(samsak->getAttackDamage());
	samsak->beRepaired(10);
	samsak->guardGate();
	dodo->attack("Mu");

	delete mu;
	delete samsak;
	delete yatong;
	delete dodo;
}
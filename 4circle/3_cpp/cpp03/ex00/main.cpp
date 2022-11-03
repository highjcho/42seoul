/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/11/03 14:47:05 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap* mu = new ClapTrap("Mu"); // new 써써도  되되는는지지
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
}
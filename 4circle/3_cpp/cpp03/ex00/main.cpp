/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/26 16:06:48 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap mu = ClapTrap("Mu");
	ClapTrap samsak = ClapTrap("Samsak");
	ClapTrap yatong = ClapTrap("Yatong");

	while (mu.getEnergy()) {
		mu.attack("Samsak");
		samsak.takeDamage(mu.getAttackDamage());
	}
	mu.attack("Samsak");
	samsak.attack("Yatong");
	yatong.takeDamage(samsak.getAttackDamage());
	samsak.beRepaired(10);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 00:21:44 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap mu = ScavTrap("Mu");
	ScavTrap samsak = ScavTrap("Samsak");
	ClapTrap yatong = ClapTrap("Yatong");
	ClapTrap dodo = ClapTrap("Dodo");

	mu.attack("Samsak");
	samsak.takeDamage(mu.getAttackDamage());
	samsak.attack("Yatong");
	yatong.takeDamage(samsak.getAttackDamage());
	samsak.beRepaired(10);
	samsak.guardGate();
	dodo.attack("Mu");
}
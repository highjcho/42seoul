/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/20 19:03:11 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap mu = ScavTrap("Mu");
	FragTrap samsak = FragTrap("Samsak");
	ClapTrap yatong = ClapTrap("Yatong");
	ClapTrap dodo = ClapTrap("Dodo");
	
	mu.attack("Samsak");
	samsak.takeDamage(mu.getAttackDamage());
	mu.attack("Samsak");
	samsak.attack("Yatong");
	yatong.takeDamage(samsak.getAttackDamage());
	mu.guardGate();
	samsak.beRepaired(10);
	samsak.highFivesGuys();
	dodo.attack("Mu");
}
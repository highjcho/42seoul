/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/26 16:20:02 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap mu = ScavTrap("Mu");
	FragTrap samsak = FragTrap("Samsak");
	ClapTrap yatong = ClapTrap("Yatong");
	
	mu.attack("Samsak");
	samsak.takeDamage(mu.getAttackDamage());
	samsak.attack("Yatong");
	yatong.takeDamage(samsak.getAttackDamage());
	mu.guardGate();
	samsak.beRepaired(10);
	samsak.highFivesGuys();
}
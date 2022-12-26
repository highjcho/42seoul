/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:41 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/26 14:08:40 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	ScavTrap mu = ScavTrap("Mu");
	FragTrap samsak = FragTrap("Samsak");
	DiamondTrap raegi = DiamondTrap("Raegi");
	
	mu.attack("Samsak");
	samsak.takeDamage(mu.getAttackDamage());
	samsak.attack("raegi");
	raegi.takeDamage(samsak.getAttackDamage());
	mu.guardGate();
	samsak.beRepaired(10);
	samsak.highFivesGuys();
	raegi.guardGate();
	raegi.highFivesGuys();
	raegi.whoAmI();
}
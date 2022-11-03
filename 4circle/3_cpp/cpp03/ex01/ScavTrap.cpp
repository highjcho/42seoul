/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:17:42 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/11/03 14:50:32 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "You can't call this";
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap("Parent ClapTrap"), _name(name), _hit(100), _energy(50), _attackDamage(20)
{
	std::cout << [Create] I'm
}
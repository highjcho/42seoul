/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:17:01 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 12:37:41 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

# define S_HIT 100
# define S_ENERGY 50
# define S_ATTACK 20

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &obj);
		ScavTrap& operator=(const ScavTrap &obj);
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate();
};

#endif
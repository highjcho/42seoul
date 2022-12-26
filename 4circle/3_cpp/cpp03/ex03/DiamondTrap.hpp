/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:18:13 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/26 12:09:39 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		DiamondTrap();
		std::string _name;

	public:
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &obj);
		DiamondTrap& operator=(const DiamondTrap &obj);
		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI();
};

#endif
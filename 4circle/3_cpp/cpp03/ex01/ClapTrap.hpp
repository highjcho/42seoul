/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:57:14 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/11/03 14:47:41 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		ClapTrap();

	protected:
		std::string _name;
		unsigned int _hit;
		unsigned int _energy;
		unsigned int _attackDamage;

	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &obj);
		ClapTrap& operator=(const ClapTrap &obj);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		unsigned int getHit() const;
		unsigned int getEnergy() const ;
		unsigned int getAttackDamage() const;
		void showStatus() const;
};

#endif
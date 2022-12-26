/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:57:14 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/26 16:02:28 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define CLAP	"\033[0;32m"
# define SCAV	"\033[1;31m"
# define FRAG	"\033[1;33m"
# define DIA	"\033[1;36m"
# define EOC	"\033[0;0m"

class ClapTrap {
	protected:
		ClapTrap();
		std::string _name;
		unsigned int _hit;
		unsigned int _energy;
		unsigned int _attackDamage;

	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &obj);
		ClapTrap& operator=(const ClapTrap &obj);
		virtual ~ClapTrap();

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		unsigned int getHit() const;
		unsigned int getEnergy() const ;
		unsigned int getAttackDamage() const;
		void showStatus() const;
};

#endif
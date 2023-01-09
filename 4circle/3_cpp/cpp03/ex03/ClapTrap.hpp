/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:19 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 11:53:30 by hyunjcho         ###   ########.fr       */
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
# define C_HIT	10
# define C_ENERGY 10
# define C_ATTACK 0
# define C_NAME "CLAP"

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

		virtual std::string getName() const;
		unsigned int getHit() const;
		unsigned int getEnergy() const ;
		unsigned int getAttackDamage() const;
		void showStatus() const;
};

#endif
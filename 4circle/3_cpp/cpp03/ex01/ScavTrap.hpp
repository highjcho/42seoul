/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:17:39 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/11/03 14:51:30 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

class ScavTrap : public ClapTrap {
	private:
		ScavTrap();

	public:
		void guardGate();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &obj);
		ScavTrap& operator=(const ScavTrap &obj);
		~ScavTrap();
}

#endif
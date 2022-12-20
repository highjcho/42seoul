/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:17:39 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/20 12:11:51 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:
		FragTrap();

	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &obj);
		FragTrap& operator=(const FragTrap &obj);
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys();
};

#endif
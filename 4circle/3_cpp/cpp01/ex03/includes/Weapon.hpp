/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:02:28 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:53:37 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(const std::string type);
		std::string getType() const;
		void setType(const std::string type);
};

#endif
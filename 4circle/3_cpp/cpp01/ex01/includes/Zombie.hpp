/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:56:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:40:38 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		static Zombie* zombieHorde(const int N, const std::string name);
		void setName(const std::string name);
		void announce(void) const;
};

#endif
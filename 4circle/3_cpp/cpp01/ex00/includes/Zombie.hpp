/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:26 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:38:57 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(const std::string name);
		~Zombie();
		static Zombie* newZombie(const std::string name);
		static void randomChump(const std::string name);
		void announce(void) const;
};

#endif
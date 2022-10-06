/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:26 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/05 19:10:29 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define MAX_WIDTH 10

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		~Zombie();
		static Zombie* newZombie(std::string name);
		static void randomChump(std::string name);
		void announce(void);
};


#endif
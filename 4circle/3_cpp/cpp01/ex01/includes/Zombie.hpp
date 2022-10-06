/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:56:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/05 18:54:23 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>

# define MAX_WIDTH 10

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie();
		~Zombie();
		static Zombie* zombieHorde(int N, std::string name);
		void setName(std::string name);
		void announce(void);
};


#endif
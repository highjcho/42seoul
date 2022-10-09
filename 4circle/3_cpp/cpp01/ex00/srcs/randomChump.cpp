/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:52 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:36:29 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

void Zombie::randomChump(const std::string name) {
	Zombie zombie = Zombie(name);
	zombie.announce();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:36:16 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/02 19:17:16 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

# define SLOT 4

class Character : public ICharacter {
	private:
		AMateria* _inventory[4];
		int _quantity;

	public:
		Character();
		Character(std::string const name);
		Character(const Character &obj);
		Character& operator=(const Character &obj);
		~Character();

		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		int findIdx();
		void showMateriaStatus();
};

#endif
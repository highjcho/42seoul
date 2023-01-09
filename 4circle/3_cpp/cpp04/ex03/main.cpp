/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:59:26 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 16:53:57 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0)
			src->learnMateria(new Ice());
		else
			src->learnMateria(new Cure());
	}

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	AMateria* ice;
	AMateria* cure;
	AMateria* tmp;
	ice = src->createMateria("ice");
	me->equip(ice);
	cure = src->createMateria("cure");
	me->equip(cure);
	tmp = src->createMateria("nothing");
	me->showMateriaStatus();
	me->unequip(3);
	me->unequip(0);
	me->showMateriaStatus();
	tmp = src->createMateria("ice");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(7, *bob);
	
	delete ice;
	delete bob;
	delete me;
	delete src;
	
	return 0;
}
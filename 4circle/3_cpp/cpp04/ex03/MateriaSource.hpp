/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:52:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/02 19:06:35 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

# define SLOT 4

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _materias[4];
		int _quantity;

	public :
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria* materia);
		AMateria* findMateria(std::string const& type);
		AMateria* createMateria(std::string const& type);
};

#endif
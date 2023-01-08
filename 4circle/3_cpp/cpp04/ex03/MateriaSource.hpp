/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:52:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 20:29:08 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

# define SLOT 4

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _materias[4];
		int _quantity;

	public :
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource& operator=(const MateriaSource &obj);
		~MateriaSource();

		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const& type);
		
		AMateria* findMateria(std::string const& type);
		AMateria* getMateria(const int i) const;
		int getQuantity() const;
};

#endif
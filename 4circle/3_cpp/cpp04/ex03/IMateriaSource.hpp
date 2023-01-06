/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:42:33 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 14:13:09 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
	public :
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria* materia) = 0;
		virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif
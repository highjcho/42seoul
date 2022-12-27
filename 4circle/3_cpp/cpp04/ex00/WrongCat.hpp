/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:44:40 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 16:38:34 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat &obj);
		WrongCat& operator=(const WrongCat &obj);
		~WrongCat();

		void makeSound() const;
		std::string getType() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:44:40 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 18:29:54 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain* _brain;
		
	public:
		Cat();
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		~Cat();

		void makeSound() const;
		std::string getType() const;
		Brain* getBrain() const;
};

#endif
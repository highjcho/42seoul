/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:47:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 18:04:16 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

# define MAX 10

class Brain {
	private:
		std::string _ideas[100];
		int _idx;
	
	public :
		Brain();
		Brain(const Brain &obj);
		Brain& operator=(const Brain &obj);
		~Brain();
		
		void setIdea(const std::string &idea);
		std::string getIdea(int i) const;
};

#endif
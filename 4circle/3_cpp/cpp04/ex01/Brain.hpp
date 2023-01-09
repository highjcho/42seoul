/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:47:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 19:08:29 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

# define MAX 100

class Brain {
	private:
		std::string _ideas[MAX];
		int _idx;
	
	public :
		Brain();
		Brain(const Brain &obj);
		Brain& operator=(const Brain &obj);
		~Brain();
		
		void setIdea(const std::string &idea);
		std::string getIdea(int i) const;
		int getIdx() const;
};

#endif
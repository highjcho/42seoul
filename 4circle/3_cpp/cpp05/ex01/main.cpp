/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:02:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 12:42:42 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat mu = Bureaucrat("mu", 2);
	Bureaucrat samsak = Bureaucrat("samsak", 15);

	Form home = Form("Home", 5, 3);
	std::cout << mu;
	std::cout << samsak;
	std::cout << home;
	mu.signForm(home);
	std::cout << home;
	samsak.signForm(home);
	std::cout << home;
}
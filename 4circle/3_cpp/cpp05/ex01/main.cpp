/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:02:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/11 15:54:32 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat mu = Bureaucrat("mu", 2);
	Bureaucrat samsak = Bureaucrat("samsak", 15);

	Form home = Form("Home", 5, 3);
	Form copy_home = Form(home);
	std::cout << "[Form info] - " << home;
	std::cout << "[Form info] - " << copy_home;
	mu.signForm(home);
	std::cout << "[Form info] - " << home;
	samsak.signForm(home);
	std::cout << "[Form info] - " << home;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:51:53 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 21:54:37 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "[Usage] ./convert <input>" << std::endl;
		return (1);
	}
	Convert c = Convert(argv[1]);
	c.print();
	return 0;
}
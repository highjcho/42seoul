/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:02:17 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/20 21:03:24 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(3, 8);
	Point b(0, 4);
	Point c(0, 0);
	Point p1(2, 1);
	Point p2(2, 0);
	Point p3(6, 8);

	std::cout << "Point a.x = " << a.getX() << " a.y = " << a.getY() << std::endl;
	std::cout << "Point b.x = " << b.getX() << " b.y = " << b.getY() << std::endl;
	std::cout << "Point c.x = " << c.getX() << " c.y = " << c.getY() << std::endl;
	std::cout << "Point p1.x = " << p1.getX() << " p1.y = " << p1.getY() << std::endl;
	std::cout << "Point p2.x = " << p2.getX() << " p2.y = " << p2.getY() << std::endl;
	std::cout << "Point p3.x = " << p3.getX() << " p3.y = " << p3.getY() << std::endl;
	
	if (bsp(a, b, c, p1))
		std::cout << "p1 is in the triangle" << std::endl;
	else
		std::cout << "p1 is out of the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "p2 is in the triangle" << std::endl;
	else
		std::cout << "p2 is out of the triangle" << std::endl;
	if (bsp(a, b, c, p3))
		std::cout << "p3 is in the triangle" << std::endl;
	else
		std::cout << "p3 is out of the triangle" << std::endl;

	return 0;
}
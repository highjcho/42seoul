/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:02:17 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/20 01:39:56 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(2, 2);
	Point b(0, 0);
	Point c(3, 0);
	Point p1(2, 0);
	Point p2(1, 7);
	Point p3(5, 5);

	std::cout << "Point a.x = " << a.getX() << " a.y = " << a.getY() << std::endl;
	std::cout << "Point b.x = " << b.getX() << " b.y = " << b.getY() << std::endl;
	std::cout << "Point c.x = " << c.getX() << " c.y = " << c.getY() << std::endl;
	std::cout << "Point p1.x = " << p1.getX() << " p1y = " << p1.getY() << std::endl;
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
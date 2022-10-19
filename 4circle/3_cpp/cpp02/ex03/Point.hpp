/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:01:14 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/20 01:01:03 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &obj);
		Point& operator=(const Point& obj);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
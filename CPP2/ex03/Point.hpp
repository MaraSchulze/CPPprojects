/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:17:21 by marschul          #+#    #+#             */
/*   Updated: 2024/01/22 22:11:47 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;

    Point&	operator=(const Point& other);
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;
    ~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif 
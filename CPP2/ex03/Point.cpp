/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:17:12 by marschul          #+#    #+#             */
/*   Updated: 2024/01/22 22:11:53 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0.0f), _y(0.0f) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

const Fixed&	Point::getX(void) const {
	return _x;
}

const Fixed&	Point::getY(void) const {
	return _y;
}

Point::~Point() {}

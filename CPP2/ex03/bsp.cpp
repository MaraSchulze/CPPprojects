/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:08:20 by marschul          #+#    #+#             */
/*   Updated: 2024/01/22 13:52:55 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int orientation(const Point& a, const Point& b, const Point& point) {
	Fixed	vector1_x = b.getX() - a.getX();
	Fixed	vector1_y = b.getY() - a.getY();
	Fixed	vector2_x = point.getX() - a.getX();
	Fixed	vector2_y = point.getY() - a.getY();
    Fixed 	crossProduct = vector1_x * vector2_y - vector1_y * vector2_x;

    if (crossProduct > 0)
        return 1;
	else 
        return -1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	int	orientationAB;
	int	orientationBC;
	int	orientationCA;

	orientationAB = orientation(a, b, point);
	orientationBC = orientation(b, c, point);
	orientationCA = orientation(c, a, point);
	if (orientationAB + orientationBC + orientationCA == 3 || \
		orientationAB + orientationBC + orientationCA == -3)
		return true;
	else
		return false;
}

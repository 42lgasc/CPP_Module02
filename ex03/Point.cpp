/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:56:25 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/08 21:57:12 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


// Statics

bool	Point::bsp
		(const Point & a, const Point & b, const Point & c, const Point & p) {
	if (! c.left_of(a, b) && ! c.left_of(b, a))
		return false;
	if (c.left_of(a, b))
			return p.left_of(a, b) && p.left_of(b, c) && p.left_of(c, a);
	else	return p.left_of(b, a) && p.left_of(c, b) && p.left_of(a, c);
}


// Canonical Four

Point::Point	(void) : x (0), y (0) {}
Point::Point	(const Point & p) { *this = p; }
const Point		& Point::operator = (const Point & p)
				{ x = p.x; y = p.y; return *this; }
Point::~ Point	() {}


// other Constructors

Point::Point	(const Fixed & x, const Fixed & y) : x (x), y (y) {}


// Operators

bool	Point::operator == (const Point & p) const
		{ return x == p.x && y == p.y; }


// Methods

///Returns whether the point is **strictly** to
///	the _left_ of a _line_ drawn from `a` to `b`.
///(Thus returns `false` when no line can be drawn
///	or if the point rest exactly upon the line.)
bool	Point::left_of(const Point & a, const Point & b) const {
	if (a == b) return false;
	if (a.x == b.x) {
		if (a.y < b.y)	return x < a.x;
		else			return x > a.x;
	}
	const Fixed	& slope = (b.y - a.y) / (b.x - a.x);
	const Fixed	& vertical_offset = a.y - slope * a.x;
	if (a.x < b.x)	return y > x * slope + vertical_offset;
	else			return y < x * slope + vertical_offset;
}

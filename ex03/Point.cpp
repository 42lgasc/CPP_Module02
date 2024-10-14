/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:56:25 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/14 19:58:21 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%:include "Point.hpp"

%:define UNUSED	__attribute__ ((unused))


// Statics

bool	Point::bsp(const Point bitand a, const Point bitand b,
		const Point bitand c, const Point bitand p) <%
	if (not c.left_of(a, b) and not c.left_of(b, a))
		return false;
	if (c.left_of(a, b))
			return p.left_of(a, b) and p.left_of(b, c) and p.left_of(c, a);
	else	return p.left_of(b, a) and p.left_of(c, b) and p.left_of(a, c);
%>


// Canonical Four

Point::Point		(void)					: x (0	), y (	0) <%%>
Point::Point		(const Point bitand p)	: x (p.x), y (p.y) <%%>
///No exception safety. Also, sabotage upon derivation.
///https://www.reddit.com/r/cpp/comments/bgv9mt/comment/elnrerq
// https://discordapp.com/channels/1031300918840402021/1031308066190282752
Point				bitand Point::operator = (UNUSED const Point bitand p) <%
	///https://isocpp.org/wiki/faq/assignment-operators#self-assignment-why
	const Point bitand	copy (p);

	this->~ Point ();
	new (this) Point (copy);
	return *this;
%>
Point::compl Point	(void) <%%>


// other Constructors

Point::Point	(const Fixed bitand x, const Fixed bitand y) : x (x), y (y) <%%>


// Operators

bool	Point::operator == (const Point bitand p) const
		<% return x == p.x and y == p.y; %>


// Methods

///Returns whether the point is **strictly** to
///	the _left_ of a _line_ drawn from `a` to `b`.
///(Thus returns `false` when no line can be drawn
///	or if the point rest exactly upon the line.)
bool	Point::left_of(const Point bitand a, const Point bitand b) const <%
	if (a == b) return false;
	if (a.x == b.x) <%
		if (a.y < b.y)	return x < a.x;
		else			return x > a.x;
	%>
	const Fixed	bitand slope = (b.y - a.y) / (b.x - a.x);
	const Fixed	bitand vertical_offset = a.y - slope * a.x;
	if (a.x < b.x)	return y > x * slope + vertical_offset;
	else			return y < x * slope + vertical_offset;
%>

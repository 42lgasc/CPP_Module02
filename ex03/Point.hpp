/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:56:43 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/08 21:37:49 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	Fixed	x, y;

public:
	static bool	bsp(const Point & a, const Point & b,
					const Point & c, const Point & p) WARN_UNUSED_RESULT;

	Point		(void);
	Point		(const Point &);
	const Point	& operator = (const Point &);
	~ Point		();

	Point	(const Fixed & x, const Fixed & y);

	bool	operator == (const Point &) const WARN_UNUSED_RESULT;

	bool	left_of(const Point & a, const Point & b) const WARN_UNUSED_RESULT;
};
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:56:43 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/14 19:58:03 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%:ifndef POINT_HPP
%: define POINT_HPP

%: include "Fixed.hpp"

class Point <%
	const Fixed	x, y;

public:
	static bool	bsp(const Point bitand a, const Point bitand b,
		const Point bitand c, const Point bitand p) WARN_UNUSED_RESULT;

	Point		(void);
	Point		(const Point bitand);
	Point		bitand operator = (const Point bitand);
	compl Point	(void);

	Point	(const Fixed bitand x, const Fixed bitand y);

	bool	operator == (const Point bitand) const WARN_UNUSED_RESULT;

	bool	left_of(const Point bitand a, const Point bitand b) const
		WARN_UNUSED_RESULT;
%>;
%:endif

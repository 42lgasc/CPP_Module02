/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:17:37 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/14 17:05:38 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%:include "Point.hpp"

%:include <iostream> // cout, endl

///TODO
int	main(void) <%
	Point p;

	p = Point (Fixed (1), Fixed (1));
	std::cout << (not p.left_of(Point (Fixed (1), Fixed (0)),
								Point (Fixed (1), Fixed (2)))
			and not p.left_of(	Point (Fixed (1), Fixed (2)),
								Point (Fixed (1), Fixed (0)))
			and not p.left_of(	Point (Fixed (0), Fixed (1)),
								Point (Fixed (2), Fixed (1)))
			and not p.left_of(	Point (Fixed (2), Fixed (1)),
								Point (Fixed (0), Fixed (1)))) << std::endl;
	return Point::bsp(Point (), Point (Fixed (3), Fixed (4)),
			Point (Fixed (-.5f), Fixed (8.625744193f)), p);
%>

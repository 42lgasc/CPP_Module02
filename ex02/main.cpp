/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:59:21 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/05 15:01:52 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	main(void) {
	Fixed		a;
	Fixed const	b (Fixed(5.05f) * Fixed(2));

	std::cout << a		<< std::endl;
	std::cout << ++ a	<< std::endl;
	std::cout << a		<< std::endl;
	std::cout << a ++	<< std::endl;
	std::cout << a		<< std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}

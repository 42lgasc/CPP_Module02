/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:20:17 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/04 20:26:44 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <climits>	// INT_MIN, WORD_BIT
#include <iostream>	// cout, endl


template <typename T, typename S>
const S	& ft_assert_type (const S & scrutinee)
		{ const T *const test = & scrutinee; (void) test; return scrutinee; }


// Canonical Four

Fixed::Fixed	(void) : raw ()
				{ std::cout << "Default constructor called" << std::endl; }
Fixed::Fixed	(const Fixed & f) {
	std::cout << "Copy constructor called" << std::endl;
	raw = f.getRawBits();
}

Fixed::~ Fixed	(void) { std::cout << "Destructor called" << std::endl; }

Fixed			& Fixed::operator = (const Fixed & f) {
	std::cout << "Copy assignment operator called" << std::endl;
	raw = f.getRawBits();
	return *this;
}


// Special miscellaneous

///Leftmost bits will be lost. The bit loss is equal to the
///					amount of bit which have dedication to the fractional part.
Fixed::Fixed	(const int & i) {
	std::cout << "Int constructor called" << std::endl;
	raw = (ft_assert_type<int>(raw), static_cast <unsigned> (i))
		<< c_fractional_bits;
	if (i < 0) raw |= (ft_assert_type<int>(raw), INT_MIN);
}

///No behaviour definition if the value of `f` fit not the type of the
///			internal representation, or if `unsigned long` is insufficiently
///				wide to represent the value of `f` with sufficient precision.
Fixed::Fixed	(const float & f) {
	std::cout << "Float constructor called" << std::endl;
	raw = (ft_assert_type<int>(raw), static_cast <unsigned> (f))
		<< c_fractional_bits;
	if (f < 0) raw |= (ft_assert_type<int>(raw), INT_MIN);
	for (unsigned char bit = 0; bit < c_fractional_bits; ++ bit)
		raw |= static_cast <unsigned long> (f * (2 << bit)) % 2
			<< (c_fractional_bits - 1 - bit);
}


// Accessors

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return raw;
}
void	Fixed::setRawBits(const int & raw) {
	std::cout << "getRawBits member function called" << std::endl;
	this->raw = raw;
}


// Converters

int	Fixed::toInt(void) const {
	int	i = static_cast <unsigned> (ft_assert_type<int>(raw))
		>> c_fractional_bits;
	if (ft_assert_type<int>(raw) & INT_MIN)
		i |= (ft_assert_type<int>(raw), static_cast <unsigned> (-1))
			<< ((ft_assert_type<int>(raw), WORD_BIT) - c_fractional_bits);
	return i;
}

float	Fixed::toFloat(void) const {
	float	f = toInt();
	for (unsigned char bits = 0; bits < c_fractional_bits; ++ bits)
		f += 1. / ((static_cast <unsigned> (ft_assert_type<int>(raw))
					>> (c_fractional_bits - 1 - bits)) % 2 << bits);
	return f;
}


// frens ·‿·

template <> std::ostream	& operator << (std::ostream & s, const Fixed & f)
							{ return s << f.toFloat(); }

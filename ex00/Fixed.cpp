/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:20:17 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/08 19:39:16 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <climits>	// INT_MIN, WORD_BIT
#include <cmath>	// roundf
#include <iostream>	// cout, endl

#ifndef METHOD_INFO
# define METHOD_INFO	NOT_DEF	// Use the preprocessor flag for definition
#endif
#ifndef SPECIAL_INFO
# define SPECIAL_INFO	NOT_DEF	// Use the preprocessor flag for definition
#endif

#define FAINT	"\x1B[2m"
#define REGULAR	"\x1B[22m"

#define UNUSED	__attribute__ ((unused))

template <typename T, typename S>
const S	& ft_assert_type(const S & scrutinee)
		{ const T *const test (& scrutinee); (void) test; return scrutinee; }



// Canonical Four

Fixed::Fixed	(void) : raw (0) {
	SPECIAL_INFO && std::cout << FAINT "Default constructor called"	REGULAR
		<< std::endl;
}
Fixed::Fixed	(const Fixed & f) {
	SPECIAL_INFO && std::cout << FAINT "Copy constructor called"	REGULAR
		<< std::endl;
	*this = f;
}

Fixed::~ Fixed	(void) {
	SPECIAL_INFO && std::cout << FAINT "Destructor called" REGULAR << std::endl;
}

Fixed			& Fixed::operator = (const Fixed & f) {
	SPECIAL_INFO && std::cout << FAINT "Copy assignment operator called" REGULAR
		<< std::endl;
	raw = f.getRawBits();
	return *this;
}


// Statics

		Fixed	& Fixed::min(		Fixed	& left, 		Fixed	& right)
				{ if (left > right) return right; return left; }
const	Fixed	& Fixed::min(const	Fixed	& left, const	Fixed	& right)
				{ if (left > right) return right; return left; }
		Fixed	& Fixed::max(		Fixed	& left, 		Fixed	& right)
				{ if (left < right) return right; return left; }
const	Fixed	& Fixed::max(const	Fixed	& left, const	Fixed	& right)
				{ if (left < right) return right; return left; }


// other Constructors

///Leftmost bits will be lost. The bit loss is equal to the
///					amount of bit which have dedication to the fractional part.
Fixed::Fixed	(const int & i) {
	SPECIAL_INFO
		&& std::cout << FAINT "Int constructor called" REGULAR << std::endl;
	raw = i * (1 << c_fractional_bits);
	if (i < 0) raw |= (ft_assert_type<int>(raw), INT_MIN);
}

///No behaviour definition if the value of `f` fit not the type of the
///			internal representation, or if `unsigned long` is insufficiently
///				wide to represent the value of `f` with sufficient precision.
Fixed::Fixed	(const float & f) {
	SPECIAL_INFO
		&& std::cout << FAINT "Float constructor called" REGULAR << std::endl;
	raw = roundf(f * (1 << c_fractional_bits));
	if (f < 0) raw |= (ft_assert_type<int>(raw), INT_MIN);
}


// Accessors

int		Fixed::getRawBits(void) const {
	METHOD_INFO && std::cout
		<< FAINT "getRawBits member function called" REGULAR << std::endl;
	return raw;
}
void	Fixed::setRawBits(const int & raw) {
	METHOD_INFO && std::cout
		<< FAINT "getRawBits member function called" REGULAR << std::endl;
	this->raw = raw;
}


// Operators

const Fixed	& Fixed::operator ++ (void) { ++ raw; return *this; }
const Fixed	& Fixed::operator ++ (UNUSED const int postfix)
			{ const Fixed & before (*this); ++ raw; return before; }
const Fixed	& Fixed::operator -- (void) { -- raw; return *this; }
const Fixed	& Fixed::operator -- (UNUSED const int postfix)
			{ const Fixed & before (*this); -- raw; return before; }

const Fixed	Fixed::operator + (const Fixed & f) const
			{ return Fixed (raw + f.raw); }
const Fixed	Fixed::operator - (const Fixed & f) const
			{ return Fixed (raw - f.raw); }
const Fixed	Fixed::operator * (const Fixed & f) const
			{ return Fixed (toFloat() * f.toFloat()); }
const Fixed	Fixed::operator / (const Fixed & f) const
			{ return Fixed (toFloat() / f.toFloat()); }

bool	Fixed::operator < (const Fixed & f) const { return raw < f.raw; }
///https://en.cppreference.com/w/cpp/language/operators#Comparison_operators
bool	Fixed::operator > (const Fixed & f) const { return f < *this; }
///https://en.cppreference.com/w/cpp/language/operators#Comparison_operators
bool	Fixed::operator <= (const Fixed & f) const { return ! (*this > f); }
///https://en.cppreference.com/w/cpp/language/operators#Comparison_operators
bool	Fixed::operator >= (const Fixed & f) const { return ! (*this < f); }

bool	Fixed::operator == (const Fixed & f) const { return raw == f.raw; }
///https://en.cppreference.com/w/cpp/language/operators#Comparison_operators
bool	Fixed::operator != (const Fixed & f) const { return ! (*this == f); }


// Converters

int	Fixed::toInt(void) const {
	int	i (raw / (1 << c_fractional_bits));
	if (ft_assert_type<int>(raw) & INT_MIN)
		i |= static_cast <unsigned> (ft_assert_type<int>(raw), -1)
			<< ((ft_assert_type<int>(raw), WORD_BIT) - c_fractional_bits);
	return i;
}

float	Fixed::toFloat(void) const {
	return 1. * raw / (1 << c_fractional_bits);
}


// frens ·‿·

template <> std::ostream	& operator << (std::ostream & s, const Fixed & f)
							{ return s << f.toFloat(); }

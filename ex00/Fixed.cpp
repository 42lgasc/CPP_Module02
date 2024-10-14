/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:20:17 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/14 18:00:04 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%:include "Fixed.hpp"

%:include <climits>	// INT_MIN, WORD_BIT
%:include <cmath>	// roundf
%:include <iostream>	// cout, endl

%:ifndef METHOD_INFO
%: define METHOD_INFO	NOT_DEF	// Use the preprocessor flag for definition
%:endif
%:ifndef SPECIAL_INFO
%: define SPECIAL_INFO	NOT_DEF	// Use the preprocessor flag for definition
%:endif

%:define FAINT		"\x1B[2m"
%:define REGULAR	"\x1B[22m"

%:define UNUSED	__attribute__ ((unused))

template <typename T, typename S>
const S	bitand ft_assert_type(const S bitand scrutinee)
		<% UNUSED const T *const test (bitand scrutinee); return scrutinee; %>



// Canonical Four

Fixed::Fixed		(void) : raw (0) <%
	if (SPECIAL_INFO)
		std::cout << FAINT "Default constructor called" REGULAR << std::endl;
%>
Fixed::Fixed		(const Fixed bitand f) <%
	if (SPECIAL_INFO)
		std::cout << FAINT "Copy constructor called with " << f << REGULAR
			<< std::endl;
	*this = f;
%>
Fixed				bitand Fixed::operator = (const Fixed bitand f) <%
	if (SPECIAL_INFO)
		std::cout << FAINT "Copy assignment operator called with " << f
			<< REGULAR << std::endl;
	raw = f.getRawBits();
	return *this;
%>
Fixed::compl Fixed	(void) <%
	if (SPECIAL_INFO)
		std::cout << FAINT "Destructor called" REGULAR << std::endl;
%>


// Constructors for conversion or with a name

///Leftmost bits will be lost. The bit loss is equal to the
///					amount of bit which have dedication to the fractional part.
Fixed::Fixed	(const int bitand i) <%
	if (SPECIAL_INFO)
		std::cout << FAINT "Int constructor called with " << i << REGULAR
			<< std::endl;
	raw = i * (1 << c_fractional_bits);
	if (i < 0) raw or_eq (ft_assert_type<int>(raw), INT_MIN);
%>
///No behaviour definition if the value of `f` fit not the type of the
///			internal representation, or if `unsigned long` is insufficiently
///				wide to represent the value of `f` with sufficient precision.
Fixed::Fixed	(const float bitand f) <%
	if (SPECIAL_INFO)
		std::cout << FAINT "Float constructor called with " << f << REGULAR
			<< std::endl;
	raw = roundf(f * (1 << c_fractional_bits));
	if (f < 0) raw or_eq (ft_assert_type<int>(raw), INT_MIN);
%>

Fixed	Fixed::fromRawBits(const int bitand raw)
		<% Fixed	f; f.setRawBits(raw); return f; %>


// Accessors

int		Fixed::getRawBits(void) const <%
	if (METHOD_INFO)
		std::cout << FAINT "getRawBits member function called" REGULAR
			<< std::endl;
	return raw;
%>
void	Fixed::setRawBits(const int bitand raw) <%
	if (METHOD_INFO)
		std::cout << FAINT "setRawBits member function called with " << std::hex
			<< raw << REGULAR << std::endl;
	this->raw = raw;
%>


// Operators

Fixed	bitand	Fixed::operator ++ (void) <%	++ raw; return *this;	%>
Fixed			Fixed::operator ++ (UNUSED const int postfix)
				<% const Fixed ante (*this);	++ raw; return ante;	%>
Fixed	bitand	Fixed::operator -- (void) <%	-- raw; return *this;	%>
Fixed			Fixed::operator -- (UNUSED const int postfix)
				<% const Fixed ante (*this);	-- raw; return ante;	%>

Fixed	Fixed::operator + (const Fixed bitand f) const
		<% return Fixed::fromRawBits(raw + f.raw); %>
Fixed	Fixed::operator - (const Fixed bitand f) const
		<% return Fixed::fromRawBits(raw - f.raw); %>

Fixed	Fixed::operator * (const Fixed bitand f) const
		<% return Fixed (toFloat() * f.toFloat()); %>
Fixed	Fixed::operator / (const Fixed bitand f) const
		<% return Fixed (toFloat() / f.toFloat()); %>

bool	Fixed::operator < (const Fixed bitand f) const <% return raw < f.raw; %>
///https://en.cppreference.com/w/cpp/language/operators#Comparison_operators
bool	Fixed::operator > (const Fixed bitand f) const <% return f < *this; %>
///https://en.cppreference.com/w/cpp/language/operators#Comparison_operators
bool	Fixed::operator <= (const Fixed bitand f) const
		<% return not (*this > f); %>
///https://en.cppreference.com/w/cpp/language/operators#Comparison_operators
bool	Fixed::operator >= (const Fixed bitand f) const
		<% return not (*this < f); %>

bool	Fixed::operator ==		(const Fixed bitand f) const
		<% return		raw		== f.raw; %>
///https://en.cppreference.com/w/cpp/language/operators#Comparison_operators
bool	Fixed::operator not_eq	(const Fixed bitand f) const
		<% return not (	*this	== f); %>


// Converters

int	Fixed::toInt(void) const <%
	int	i (raw / (1 << c_fractional_bits));
	if (ft_assert_type<int>(raw) bitand INT_MIN)
		i or_eq static_cast <unsigned> (ft_assert_type<int>(raw), -1)
			<< ((ft_assert_type<int>(raw), WORD_BIT) - c_fractional_bits);
	return i;
%>

float	Fixed::toFloat(void) const <%
	return 1. * raw / (1 << c_fractional_bits);
%>


// Statics

		Fixed	bitand Fixed::min(		Fixed bitand left,	Fixed bitand right)
				<% if (left > right) return right; return left; %>
const	Fixed	bitand Fixed::min(const	Fixed bitand left,
		const												Fixed bitand right)
				<% if (left > right) return right; return left; %>
		Fixed	bitand Fixed::max(		Fixed bitand left,	Fixed bitand right)
				<% if (left < right) return right; return left; %>
const	Fixed	bitand Fixed::max(const	Fixed bitand left,
		const												Fixed bitand right)
				<% if (left < right) return right; return left; %>


// frens ·‿·

std::ostream	bitand operator << (std::ostream bitand s, const Fixed bitand f)
				<% return s << f.toFloat(); %>

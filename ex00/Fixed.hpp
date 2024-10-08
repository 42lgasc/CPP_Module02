/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:07:10 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/08 15:48:27 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))

class Fixed {
	static const unsigned char c_fractional_bits = 8;

	int	raw;

public:
	Fixed	(void);
	Fixed	(const Fixed & f);
	~ Fixed	(void);
	Fixed	& operator = (const Fixed & f);

	static			Fixed	& min(		Fixed & left, 		Fixed & right)
							WARN_UNUSED_RESULT;
	static const	Fixed	& min(const	Fixed & left, const	Fixed & rigth)
							WARN_UNUSED_RESULT;
	static			Fixed	& max(		Fixed & left, 		Fixed & right)
							WARN_UNUSED_RESULT;
	static const	Fixed	& max(const	Fixed & left, const	Fixed & right)
							WARN_UNUSED_RESULT;

	explicit Fixed	(const int		& i);
	explicit Fixed	(const float	& f);

	int		getRawBits(void) const WARN_UNUSED_RESULT;
	void	setRawBits(const int & raw);

	const Fixed	& operator ++ (void)		WARN_UNUSED_RESULT;
	const Fixed	& operator ++ (int postfix)	WARN_UNUSED_RESULT;
	const Fixed	& operator -- (void)		WARN_UNUSED_RESULT;
	const Fixed	& operator -- (int postfix)	WARN_UNUSED_RESULT;

	const Fixed	operator + (const Fixed & f) const WARN_UNUSED_RESULT;
	const Fixed	operator - (const Fixed & f) const WARN_UNUSED_RESULT;
	const Fixed	operator * (const Fixed & f) const WARN_UNUSED_RESULT;
	const Fixed	operator / (const Fixed & f) const WARN_UNUSED_RESULT;

	bool	operator <	(const Fixed & f) const WARN_UNUSED_RESULT;
	bool	operator >	(const Fixed & f) const WARN_UNUSED_RESULT;
	bool	operator <=	(const Fixed & f) const WARN_UNUSED_RESULT;
	bool	operator >=	(const Fixed & f) const WARN_UNUSED_RESULT;

	bool	operator == (const Fixed & f) const WARN_UNUSED_RESULT;
	bool	operator != (const Fixed & f) const WARN_UNUSED_RESULT;

	float	toFloat(void)	const WARN_UNUSED_RESULT;
	int		toInt(void)		const WARN_UNUSED_RESULT;
};


// frens ·‿·

template <typename T>
T	& operator << (T & stream, const Fixed & f) WARN_UNUSED_RESULT;
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:07:10 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/04 20:25:10 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	static const unsigned char c_fractional_bits = 8;

	int	raw;

public:
	Fixed	(void);
	Fixed	(const Fixed & f);
	~ Fixed	(void);
	Fixed	& operator = (const Fixed & f);

	explicit Fixed	(const int		& i);
	explicit Fixed	(const float	& f);

	int		getRawBits(void) const __attribute__ ((warn_unused_result));
	void	setRawBits(const int & raw);

	float	toFloat(void)	const __attribute__ ((warn_unused_result));
	int		toInt(void)		const __attribute__ ((warn_unused_result));
};


// frens ·‿·

template <typename T>
T	& operator << (T & stream, const Fixed & f)
	__attribute__ ((warn_unused_result));
#endif

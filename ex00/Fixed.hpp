/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:07:10 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/14 17:06:49 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%:ifndef FIXED_HPP
%: define FIXED_HPP

%: include <ostream> // ostream

%: define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))

class Fixed <%
	static const unsigned char c_fractional_bits = 8;

	int	raw;

	static Fixed	fromRawBits(const int bitand) WARN_UNUSED_RESULT;

public:
	Fixed		(void);
	Fixed		(const Fixed bitand f);
	compl Fixed	(void);
	Fixed		bitand operator = (const Fixed bitand f);

	explicit Fixed	(const int		bitand i);
	explicit Fixed	(const float	bitand f);

	int		getRawBits(void) const WARN_UNUSED_RESULT;
	void	setRawBits(const int bitand raw);

	Fixed	bitand	operator ++ (void);
	Fixed			operator ++ (int postfix) WARN_UNUSED_RESULT;
	Fixed	bitand	operator -- (void);
	Fixed			operator -- (int postfix) WARN_UNUSED_RESULT;

	Fixed	operator + (const Fixed bitand f) const WARN_UNUSED_RESULT;
	Fixed	operator - (const Fixed bitand f) const WARN_UNUSED_RESULT;
	Fixed	operator * (const Fixed bitand f) const WARN_UNUSED_RESULT;
	Fixed	operator / (const Fixed bitand f) const WARN_UNUSED_RESULT;

	bool	operator <	(const Fixed bitand f) const WARN_UNUSED_RESULT;
	bool	operator >	(const Fixed bitand f) const WARN_UNUSED_RESULT;
	bool	operator <=	(const Fixed bitand f) const WARN_UNUSED_RESULT;
	bool	operator >=	(const Fixed bitand f) const WARN_UNUSED_RESULT;

	bool	operator ==		(const Fixed bitand f) const WARN_UNUSED_RESULT;
	bool	operator not_eq	(const Fixed bitand f) const WARN_UNUSED_RESULT;

	float	toFloat(void)	const WARN_UNUSED_RESULT;
	int		toInt(void)		const WARN_UNUSED_RESULT;

	static			Fixed	bitand min(			Fixed bitand left,
					Fixed bitand right) WARN_UNUSED_RESULT;
	static const	Fixed	bitand min(const	Fixed bitand left,
			const	Fixed bitand rigth) WARN_UNUSED_RESULT;
	static			Fixed	bitand max(			Fixed bitand left,
					Fixed bitand right) WARN_UNUSED_RESULT;
	static const	Fixed	bitand max(const	Fixed bitand left,
			const	Fixed bitand right) WARN_UNUSED_RESULT;
%>;


// frens ·‿·

std::ostream	bitand operator << (std::ostream bitand, const Fixed bitand);
%:endif

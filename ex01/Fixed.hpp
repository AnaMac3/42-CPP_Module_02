/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:30 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/19 11:39:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP
# define _FIXED_HPP

# include <iostream>
# include <cmath>

/**
 * @class	Fixed
 * @brief	Simple fixed-point number storage class.
 * 			- Stores a fixed-point number in an integer '_value', containing
 * 			both integer and fractional parts.
 * 			- Uses a class-wide constant '_fractionalBits' that indicates
 * 			how many bits of '_value' are considered fractional (8 -> scale
 * 			factor 2^8 = 256).
 * 			- Constructors:
 * 				* Default constructor
 * 				* Copy constructor
 * 				* Integer constructor
 * 				* Float constructor
 * 			- Assignment operator
 * 			- Destructor
 * 			- Raw acces methods:
 * 				* getRawBits()
 * 				* setrawBits(int)
 * 			- Conversion methods
 * 				* ToInt()
 * 				* ToFloat()
 */

class   Fixed
{
	private:
		int _value;
		static const int _fractionalBits;
		
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int input);
		Fixed(const float input);
		Fixed&	operator=(const Fixed& other);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
};

//Non-member operators
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed); 

#endif

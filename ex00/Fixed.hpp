/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:30 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/12 12:03:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP
# define _FIXED_HPP

# include <iostream>

/**
 * @class	Fixed
 * @brief	Simple fixed-point number storage class.
 * 			- Stores a fixed-point number in an integer '_value', containing
 * 			both integer and fractional parts.
 * 			- Uses a class-wide constant '_fractionalBits' that indicates
 * 			how many bits of '_value' are considered fractional.
 * 			- Declares the constructors, destructor, assignment operator,
 * 			and simple raw-get/set methods.
 */

class   Fixed
{
	private:
		int _value;
		static const int _fractionalBits;
		
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		~Fixed(void);

		Fixed& operator=(const Fixed& other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif

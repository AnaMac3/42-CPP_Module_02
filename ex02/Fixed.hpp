/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:30 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/15 12:31:47 by root             ###   ########.fr       */
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
 * 			- Destructor
 * 			- Public member operators:
 * 				* Assignment operator
 * 				* Comparision operators
 * 				* Arithmetic operators
 * 				* Increment/decrement operators
 * 			- Raw acces methods:
 * 				* getRawBits()
 * 				* setrawBits(int)
 * 			- Conversion methods
 * 				* ToInt()
 * 				* ToFloat()
 * 			- min/max
 */

class	Fixed
{
	private:
		int _value;
		static const int _fractionalBits;
		
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int input);
		Fixed(const float input);
		
		~Fixed(void);

		//Public member operators
		//Assignment operator
		Fixed&	operator=(const Fixed& other);
		//Comparision operators
		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		//Arithmetic operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		//Increment/decrement operators
		Fixed&	operator++(void); //pre-increment operator
		Fixed&	operator--(void); //pre-decrement operator
		Fixed	operator++(int); //post-increment operator
		Fixed	operator--(int); //post-decrement operator

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

//Non-member operators
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed); 

#endif

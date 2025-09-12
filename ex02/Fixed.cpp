/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:33 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/12 16:55:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief	Number of fractional bits in the fixed-point format.
 * 			- Declared 'static const': it is a class-scoped constant, meaning
 * 			there is a single shared copy for the whole class.
 * 			- The value 8 means that the lower 8 bits of '_value' are
 * 			fractional part.
 * 
 */

const int Fixed::_fractionalBits = 8;

//------------------------CONSTRUCTORS                  ------------------------

/**
 * @brief	Default constructor.
 * 			Constructs a Fixed object and initializes '_value' to 0.
 * 
 */

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief	Copy constructor.
 * 			- Signature 'const &Fixed' avoids copying the argument by value
 * 			(which would call the copy constructor recursively)
 * 			- This constructor creates a new object that is a copy of 'other'.
 * 			- The line '*this = other;' invokes the copy assignment operator:
 * 				- '*this' is an implicit pointer to the current object
 * 				desreferenciated to get a 'Fixed&' (a reference to this object)
 * 				- Assigns 'other' to this object using the 'operator=' 
 * 				implementation below, because '=' between two Fixed objects
 * 				uses 'operator='. 
 * 			- Using 'this->_value = other.getRawBits()' would not use the 
 * 			'operator=' of the class.
 * 			- Another option: this->_value = other._value -> C++ allows one
 * 			object of a class to access the private members of another object
 * 			of the same class.
 * 
 * @param other	Constant reference to the Fixed instance to copy from.
 */

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; 
	//this->_value = other._value;
	//this->_value = other.getRawBits();
}

/**
 * @brief	Constructor for integer.
 * 			- Takes an integer 'input' and converts it into fixed-point
 * 			representation. 
 * 			- Conversion rule: shift the integer left by '_fractionalBits' (8),
 * 			which is equivalent to multiplying by 2^8 = 256.
 * 			- This way, the integer part is preserved while reserving the lower
 * 			8 bits for the fractional component.
 * 			
 * 			Example:
 * 			int x = 5 -> 00000000 00000000 00000101
 * 			5 << 8 -> 00000000 00000101 00000000 = 1280
 *			We store the original int 5 as 1280, which interpreted as fixed,
 *			is 5.0
 *
 * 			Range of fixed: INT_MIN/256 INT_MAX/256
 * 
 * @param input	Integer value to convert into fixed-point format.
 */

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = input << this->_fractionalBits; 
}

/**
 * @brief	Constructor for floating-point number.
 * 			- Takes an float 'input' and converts it into fixed-point
 * 			representation. 
 * 			- Conversion rule: multiply the float by 2^8 = 256 (the fixed
 * 			scaling factor) and the round to the nearest integer using
 * 			'roundf()'
 * 			- This ensures that both integer and fractional parts are
 * 			represented in the fixed-point '_value'
 * 			
 * 			Example:
 * 			
 * 
 * @param input	Floating-point value to convert into fixed-point format.
 */
Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(input * (1 << this->_fractionalBits));
}

//------------------------DESTRUCTOR                    ------------------------

/**
 * @brief   Destroy the Fixed object.
 * 			Called automatically when the object goes out of scope or is deleted
 */

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//------------------------OPERATORS                     ------------------------

/**
 * @brief   Copy of assignment operator overload.
 * 			- Returns 'Fixed&' to avoid unnecessary copying and to allowe
 * 			expressions like 'a = b = c'
 * 			- Implementation should handle self-assignment safely.
 * 
 * @param other	Constant reference to the Fixed instance to copy from.
 * @return	Reference to this object after assignment.
 */

Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl; 
    if (this != &other)
		this->_value = other.getRawBits();
	
	return (*this);
}

//------------------------PUBLIC METHODS                ------------------------

/**
 * @brief   Returns the raw integer representation of the fixed-point number
 * 			The method is 'const' because it doesn't modeify the object.
 * 
 * @return	The '_value' integer that holds raw fixed-point bits.
 */

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

/**
 * @brief   Sets the raw integer representation fo the fixed-point number
 * 			Parameter is passed by value. 
 * 
 * @param raw	Integer raw bits to store in '_value'.
 */

void    Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}


/**
 * @brief	Convert fixed-point to integer.
 * 			- Shifts '_value' right by '_fractionalBits' (8), discarding the
 * 			fractional part.
 * 			- Equivalent to dividing the fixed-point number by 2^8 = 256
 * 
 * @return	Integer representation of the fixed-point number.
 */

int	Fixed::toInt(void) const
{
	return(this->_value >> this->_fractionalBits); //desplazamos los 8 bits a la derecha (operacion inversa)
}

/**
 * @brief	Convert fixed-point to floating-point.
 * 			- Divides '_value' by 2^8 = 256.0f to reconstruct the real number
 * 			- Returns a float with both integer and fractional parts restored.
 * 
 * @return	Floating-point representation of the fixed-point number.
 */

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fractionalBits));
}


//------------------------NON-MEMBER OPERATORS         ------------------------

/**
 * @brief	Output stream operator overload ('<<')
 * 			- Allows 'Fixed' objects to be directly inserted into output
 * 			streams like 'std::cout'
 * 			- Internally calls 'toFloat()' to display the fixed-point number
 * 			as a human-readable floating-point value.
 * 			- Returns the output strea by reference to allow chaining:
 * 			'std::cout << a << b << c; 
 * 
 * @param output	Reference to the output stream
 * @param fixed		Constant reference to the Fixed object to print
 * @return	Reference to the output stream (for chaining)
 */

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat(); 
	return (output);
}

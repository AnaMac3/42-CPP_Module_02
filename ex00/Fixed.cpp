/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:33 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/12 12:01:56 by root             ###   ########.fr       */
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

//------------------------DESTRUCTOR                    ------------------------

/**
 * @brief   Destroy the Fixed object.
 * 			Called automatically when the object goes out of scope or is deleted
 */

Fixed::~Fixed()
{
    
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
	std::cout << "getRawBits member function called" << std::endl;
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

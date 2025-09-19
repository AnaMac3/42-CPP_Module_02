/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:33 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/19 11:41:36 by root             ###   ########.fr       */
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

/**
 * @brief	Default constructor.
 * 			Constructs a Fixed object and initializes '_value' to 0.
 * 
 */

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
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
	//std::cout << "Copy constructor called" << std::endl;
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
	//std::cout << "Int constructor called" << std::endl;
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
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(input * (1 << this->_fractionalBits));
}

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
	//std::cout << "Copy assignment operator called" << std::endl; 
    if (this != &other)
		this->_value = other.getRawBits();
	
	return (*this);
}

/**
 * @brief   Destroy the Fixed object.
 * 			Called automatically when the object goes out of scope or is deleted
 */

Fixed::~Fixed()
{
   // std::cout << "Destructor called" << std::endl;
}

//------------------------Comparision operators         ------------------------

/**
 * @brief	Compare if this Fixed is strictly less than another
 * 			- Convert both opernds to float using toFloat()
 * 			- Perform the floating-point comparision using '<'
 * 			- Return the boolean result (0: false, 1: true);
 * 			
 * 			- The member is marked 'const' to garantee it will not modify *this
 * 			- The parameter is passed as constant reference to avoid the copy
 * 
 * @param other	The right-hand size Fixed to compare with (passed as constant
 * 				reference)
 * @return	True if (*this) < other, false otherwise
 */

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}

/**
 * @brief	Compare if this Fixed is strictly greater than another.
 * 			- Convert both opernds to float using toFloat()
 * 			- Compare using '>'
 * 			- Return the boolean result
 * 
 * @param other	The right-hand side Fixed to compare with (passed as constant
 * 				reference)
 * @return	True if (*this) > other, false otherwise
 */

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}

/**
 * @brief	Compare if this Fixed is less than or equal to another.
 * 			- Convert both operands to float using toFloat()
 * 			- Compare using '<='
 * 			- Return the boolean result
 * 
 * @param other	The right-hand side Fixed to compare with (passed as constant
 * 				reference)
 * @return	True if (*this) <= other, false otherwise
 */

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}

/**
 * @brief	Compare if this Fixed is greater than or equal to another.
 * 			- Convert both operands to float using toFloat()
 * 			- Compare using '>='
 * 			- Return the boolean result
 * 
 * @param other	The right-hand side Fixed to compare with (passed as constant
 * 				reference)
 * @return	True if (*this) >= other, false otherwise
 */

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}

/**
 * @brief	Equality comparision between two Fixed values.
 * 			- Convert both operands to float using toFloat()
 * 			- Compare using '=='
 * 			- Return the boolean result
 * 
 * @param other	The right-hand side Fixed to compare with (passed as constant
 * 				reference)
 * @return	True if the numeric values are equal, false otherwise.
 */

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}

/**
 * @brief	Inequality comparision between two Fixed values.
 * 			- Convert both operands to float using toFloat()
 * 			- Compare using '!='
 * 			- Return the boolean result
 * 
 * @param other	The right-hand side Fixed to compare with (passed as constant
 * 				reference)
 * @return	True if the numeric values differ, false otherwise.
 */

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}

//------------------------Arithmetic operators          ------------------------


/**
 * @brief	Add two Fixed numbers and return the fixed result.
 * 			- Convert both operands to float using toFloat()
 * 			- Compute the sum as floats
 * 			- Return the resulting fixed value
 * 
 * @param other	The right-hand operand (passed as a constant reference)
 * @return	A Fixed-point value equial to (this + other);
 */

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
}

/**
 * @brief	Substract two Fixed numbers and return the fixed result.
 * 			- Convert both operands to float using toFloat()
 * 			- Compute (this - other)
 * 			- Return the resulting fixed value
 * 
 * @param other	The right-hand operand (passed as a constant reference)
 * @return	A Fixed-point value equial to (this - other);
 */

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
}

/**
 * @brief	Multiply two Fixed numbers and return the fixed result.
 * 			- Convert both operands to float using toFloat()
 * 			- Compute the product
 * 			- Return the resulting fixed value
 * 
 * @param other	The right-hand operand (passed as a constant reference)
 * @return	A Fixed-point value equial to (this * other);
 */

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}

/**
 * @brief	Divide two Fixed numbers and return the fixed result.
 * 			- Convert both operands to float using toFloat()
 * 			- Compute (this / other). No special handling for division-by-zero
 * 			- Return the resulting fixed value
 * 
 * @param other	The right-hand operand (passed as a constant reference)
 * @return	A Fixed-point value equial to (this / other);
 */

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

//------------------------Increment/decremente operators------------------------

/**
 * @brief	Pre-increment (++x): increase the fixed value by the smallest step
 * 			and return the updated value.
 * 			- Increment internal raw '_value' by 1. (1 unit in '_value'
 * 			corresponds to 1 / (2^_fractionalBits) in real terms; with 8
 * 			fractional bits the step us 1/256)
 * 			- Return a reference to the updated object, allowing chained
 * 			pre-increments ('++(++x)') without extra copies
 * 
 * @return	A Fixed containing the incremented value (returned by reference)
 */

Fixed&	Fixed::operator++()
{
	this->_value ++;
	return (*this);
}

/**
 * @brief	Pre-decrement (--x): ecrease the fixed value by the smallest step
 * 			and return the updated value.
 * 			- Decrement internal raw '_value' by 1. (1 unit in '_value'
 * 			correspondos to 1 / (2^_fractionalBits) in real terms; with 8
 * 			fractional bits the step us 1/256)
 * 			- Return a reference to the updated object.
 * 
 * @return	A Fixed containing the decremented value (returned by reference)
 */

Fixed&	Fixed::operator--()
{
	this->_value --;
	return (*this);
}

/**
 * @brief	Post-increment operator (x++)
 * 			- Distinguishable from pre-increment by the dummy 'int' parameter.
 * 			- Creates a copy of the current object (before increment)
 * 			- Increments the internal fixed-point value of the current object
 * 			- Returns the copy, so the caller receives the value as it was
 * 			before the increment.
 * 			Example:
 * 			Fixed a = 5;
 * 			Fixed b = a++; //b gets 5, a becomes 6
 * 
 * @param int	Unused dummy int parameter (only used to differentiate syntax)
 * @return	A copy of the object before it was incremented.
 */

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++this -> _value;
	return (tmp);
}

/**
 * @brief	Post-decrement operator (x--)
 * 			- Distinguishable from pre-increment by the dummy 'int' parameter.
 * 			- Creates a copy of the current object (before decrement)
 * 			- Decrements the internal fixed-point value of the current object
 * 			- Returns the copy, so the caller receives the value as it was
 * 			before the increment.
 * 			Example:
 * 			Fixed a = 5;
 * 			Fixed b = a--; //b gets 5, a becomes 4
 * 
 * @param int	Unused dummy int parameter (only used to diffentiate syntax)
 * @return	A copy of the object before it was decremented.
 */

 
Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this; //copia temporal del objeto actual this
	--this -> _value; //se decrementa el valor interno _value del objeto fixed
	return (tmp); //se devuelve la copia creada antes del incremento
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

/**
 * @brief	Return a reference to the smaller of two Fixed objects (non-const
 * 			overload).
 * 			- Compare 'fixed1' and 'fixed2' by converting to float
 * 			- If fixed1 <= fixed2 return a reference to fixed1; otherwise,
 * 			return a reference to fixed2
 * 			
 * 			- Parameters are 'Fixed&' (non-const) so callers can pass modifiable
 * 			objects
 * 			- The function returns 'Fixed&' (non-const) to allow the caller to
 * 			modify the returned object.
 * 			- The function is declared 'static' in the class: it does not use
 * 			'this' and is called as 'Fixed::min(a, b)'
 * 			- This function returns a reference to one of the parameters. It is
 * 			the caller responsibility to ensure the referenced object outlives
 * 			the returned reference
 * 
 *  
 * @param fixed1	Left operand (modifiable)
 * @param fixed2	Right operand (modifiable)
 * @return	Reference to the smaller object
 */

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.toFloat() <= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

/**
 * @brief	Return a reference to the smaller of two Fixed object (const 
 * 			overload).
 * 			- Compare 'fixed1' and 'fixed2' by converting to float
 * 			- If fixed1 <= fixed2 return a reference to fixed1; otherwise,
 * 			return a reference to fixed2
 * 
 * 			- Accepts 'const Fixed&' so the function can be used with const
 * 			objects or temporaries
 * 			- The function is declared 'static' in the class: it does not use
 * 			'this' and is called as 'Fixed::min(a, b)'
 * 			- Returns 'const Fixed&' to prevent the caller from modifying the
 * 			returned object
 * 			- The returned reference aliases onte of the parameters; the	
 * 			caller must ensure the parameter outlives the reference
 * 
 * @param fixed1	Left operand (read-only)
 * @param fixed2	Right operand (read-only)
 * @return	Const reference to the smaller object
 */

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.toFloat() <= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}


/**
 * @brief	Return a reference to the larger of two Fixed objects (non-const
 * 			overload)
 * 			- Compare both operands using toFloat()
 * 			- Return a reference to whichever is greater
 * 
 * 			- Parameters are 'Fixed&' (non-const) so callers can pass modifiable
 * 			objects
 * 			- The function returns 'Fixed&' (non-const) to allow the caller to
 * 			modify the returned object.
 * 			- The function is declared 'static' in the class: it does not use
 * 			'this' and is called as 'Fixed::max(a, b)'
 * 			- This function returns a reference to one of the parameters. It is
 * 			the caller responsability to ensure the referenced object outlives
 * 			the returned reference
 * 
 * @param fixed1	Left operand (modifiable)
 * @param fixed2	Right operand (modifiable)
 * @return	Reference to the larger object
 */

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

/**
 * @brief	Return a reference to the larger of two Fixed object (const 
 * 			overload).
 * 			- Compare 'fixed1' and 'fixed2' by converting to float
 * 			- Return a const reference to the larger one
 * 
 * 			- Accepts 'const Fixed&' so the function can be used with const
 * 			objects or temporaries
 * 			- The function is declared 'static' in the class: it does not use
 * 			'this' and is called as 'Fixed::max(a, b)'
 * 			- Returns 'const Fixed&' to prevent the caller from modifying the
 * 			returned object
 * 			- The returned reference aliases onte of the parameters; the	
 * 			caller must ensure the parameter outlives the reference
 * 
 * @param fixed1	Left operand (read-only)
 * @param fixed2	Right operand (read-only)
 * @return	Const reference to the larger object
 */

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:27 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/15 12:41:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2)); //10.1016

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	//Mis pruebas
	std::cout << std::endl << "-----------------------------------" << std::endl;
	std::cout << "MY TESTS " << std::endl;
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << std::endl;
	
	bool result; //0: false, 1: true
	std::cout << "Comparison operators" << std::endl;
	result = a > b;
	std::cout << "a > b = " << result << std::endl;
	result = a < b;
	std::cout << "a < b = " << result << std::endl;
	result = a <= b;
	std::cout << "a <= b = " << result << std::endl;
	result = a >= b;
	std::cout << "a >= b = " << result << std::endl;
	result = a == b;
	std::cout << "a == b = " << result << std::endl;
	result = a != b;
	result = 2 == 2;
	std::cout << "2 == 2 = " << result << std::endl;
	std::cout << "a != b = " << result << std::endl;
	result = 2 != 2;
	std::cout << "2 != 2 = " << result << std::endl;
	
	std::cout << std::endl;
	std::cout << "Arithmetic operators" << std::endl;
	
	Fixed result2 = 3 + 2.5f;
	std::cout << "3 + 2.5f = " << result2 << std::endl;
	Fixed result3 = 3 - 2.5f;
	std::cout << "3 - 2.5f = " << result3 << std::endl;
	Fixed result4 = 3 * 2.5f;
	std::cout << "3 * 2.5f = " << result4 << std::endl;
	Fixed result5 = 3 / 2.5f;
	std::cout << "3 / 2.5f = " << result5 << std::endl;
	
	std::cout << std::endl;
	std::cout << "Increment/decrement operators" << std::endl;
	
	Fixed c = 5;
	Fixed d = c++;
	std::cout << "c: " << c << std::endl; //5 + 0.00390625
	std::cout << "d: " << d << std::endl; //5

	Fixed e = d--;
	std::cout << "e: " << e << std::endl; //5
	std::cout << "d: " << d << std::endl; //5 - 0.00390625

	Fixed f = 5;
	Fixed g = ++f;
	std::cout << "f: " << f << std::endl; //5 + 0.00390625
	std::cout << "g: " << g << std::endl; //5 + 0.00390625

	Fixed h = --g;
	std::cout << "g: " << g << std::endl; //5
	std::cout << "h: " << h << std::endl; //5 - 0.00390625
	
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Min/max operators" << std::endl;

	Fixed r = Fixed::max(f, h);
	std::cout << r << std::endl; //5.00391
	r = Fixed::min(f, h); //modificable because is not const
	std::cout << r << std::endl; //5
	
	Fixed const i(6.709f);
	std::cout << "i value in fixed-point format: " << i << std::endl;
	const Fixed& res = Fixed::max(i, h);
	std::cout << res << std::endl; //6.709
	//res = Fixed::min(i, h);  //cannot modify, const

	return (0);
}

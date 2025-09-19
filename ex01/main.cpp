/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:27 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/19 12:12:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);
	
	std::cout << "a is " << a << std::endl; //tiene que dar 1234.43
	std::cout << "b is " << b << std::endl; //10
	std::cout << "c is " << c << std::endl; //42.4219
	std::cout << "d is " << d << std::endl; // 10

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	//My tests

	std::cout << "------------------------------------" << std::endl;
	
	Fixed const float1(0.1f);
	std::cout << "Floating 0.1 is " << float1 << std::endl;
	std::cout << "Raw bits: " << float1.getRawBits() << std::endl;
	Fixed const float2(5.5f);
	std::cout << "Floating 5.5 is " << float2 << std::endl;
	std::cout << "Raw bits: " << float2.getRawBits() << std::endl;
	Fixed const int1(5);
	std::cout << "Integer 5 is " << int1 << std::endl;
	std::cout << "Raw bits: " << int1.getRawBits() << std::endl;
	Fixed const int2(1);
	std::cout << "Integer 1 is " << int2 << std::endl;
	std::cout << "Raw bits: " << int2.getRawBits() << std::endl;


	std::cout << std::endl;

	return (0);
}

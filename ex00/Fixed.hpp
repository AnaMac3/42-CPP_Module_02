/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:30 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/11 17:27:40 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP
# define _FIXED_HPP

# include <iostream>

class   Fixed
{
	private:
		int _fixed;
		static const int _fracBitsNb; //sintaxis correcta?
		
	public:
		Fixed(void);
		Fixed(const Fixed& other); //copy of constructor
		Fixed& operator=(const Fixed& other);//copy assignment operator overload
		
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif

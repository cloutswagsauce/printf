/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:38:21 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/13 13:50:10 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	*hex_digits;
	if (uppercase)
		hex_digits = HEX_UPPER;
	else
		hex_digits = HEX_LOWER;
	if (n >= 16)
		ft_putnbr_hex(n / 16, uppercase);
	ft_putchar_count(hex_digits[n % 16]); // create putcha + count
}

int ft_printf(const char *format, ...)
{
	va_list args_p;
	int		count;

	va_start(args_p, format);

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			// when its another %
			if (*format == '%')
			{
				ft_putchar('%');
				format ++;
				count++;
			}
			// when its a char
			else if (*format == 'c')
			{
				int ch = va_arg(args_p, int);
				ft_putchar(ch);
				format++;
				count++;
			}
			// when its a string after %
			else if (*format == 's')
			{
				char *str = va_arg(args_p, char*);
				while (*str)
				{
					ft_putchar(*str);
					str++;
					count++;
				}
				format++;
			}
			// handling ints
			// unsigned int
			else if (*format == 'u')
			{
				unsigned int u_int = va_arg(args_p, unsigned int);
				ft_putnbr(u_int);
				format++;
				count++;
			}
			// signed decimal int d
			else if (*format == 'd')
			{
				int num = va_arg(args_p, int);
				ft_putnbr(num);
				count++;
			}
			// signed decimal int i
			else if (*format == 'i')
			{
				int num = va_arg(args_p, int);
				ft_putnbr(num);
				count++;
			}
			// hexadecimal
			else if(*format == 'x')
			{
				unsigned int x = va_arg(args_p, unsigned int);
				putnbr_hex(x, 0);
			}
			else if(*format == 'X')
			{
				unsigned int x = va_arg(args_p, unsigned int);
				putnbr_hex(x, 1);
			}
			else if (*format == 'p')
			{
				void *p = va_arg(args_p, void*);
				if (!p)
					ft_putstr_count("nil"); // create putstr + count
				else {
					ft_putstr("0x", &count);
					ft_putnbr_hex((unsigned long)&p, 1);
				}
			}
			// when its just a string
		else {
			while (*format)
			{
				ft_putchar(*format);
				format++;
				count++;
			}
		}
	}
	
va_end(args_p);
return (count);
}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:27:00 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/14 11:27:00 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count = 1;
		return (count);
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}
int print_u(unsigned int n)
{
	ft_putnbr_fd(n, 1);
	return (count_digits(n));
}
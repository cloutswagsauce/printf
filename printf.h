/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:20:29 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/13 12:21:02 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
#define PRINTF_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#define HEX_UPPER = '0123456789ABCDEF'

#define HEX_LOWER = '0123456789abcdef'
int	ft_printf(const char *, ...);



#endif PRINTF_H

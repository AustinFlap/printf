/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:59:03 by avieira           #+#    #+#             */
/*   Updated: 2020/01/23 07:27:23 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		minus(const char *str)
{
	str++;
	while (*str == '0' || *str == '-')
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

int		zero(const char *str)
{
	str++;
	while (*str == '0')
		str++;
	if (*str == '-')
		return (0);
	return (1);
}

int		precision(const char *str)
{
	str++;
	while (*str != '.' && *str)
		str++;
	if (!*str)
		return (-1);
	return (ft_atoi(str + 1));
}

int		width(const char *str)
{
	str++;
	while (*str == '0' || *str == '-')
		str++;
	if (ft_isdigit(*str))
		return (ft_atoi(str));
	return (-1);
}

unsigned char*		alloc_print(int size, int zero)
{
	unsigned char *print;

	if (!(print = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	print[size] = 0;
	if (zero)
		ft_memset(print, '0', size);
	else
		ft_memset(print, ' ', size);
	return (print);
}

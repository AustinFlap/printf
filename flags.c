/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:59:03 by avieira           #+#    #+#             */
/*   Updated: 2020/01/28 04:26:37 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		minus(const char *str, char format)
{
	str++;
	while ((*str == '0' || *str == '-') && *str != format)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

int		zero(const char *str, char format)
{
	str++;
	while ((*str == '0' || *str == '-') && *str != format)
	{
		if (*str == '0')
			return (1);
		str++;
	}
	return (0);
}

int		precision(const char *str, char format, va_list ap)
{
	while (*str != format)
		str++;
	while (*str != '.' && *str != '%')
		str--;
	if (*str == '%')
		return (-1);
	if (*(str + 1) == '*')
		return (va_arg(ap, long int));
	return (ft_atoi(str + 1));
}

int		width(const char *str, char format, va_list ap)
{
	str++;
	while ((*str == '0' || *str == '-') && *str != format)
		str++;
	if (*str == '*')
		return (va_arg(ap, long int));
	else if (ft_isdigit(*str))
		return (ft_atoi(str));
	return (0);
}

char*		alloc_print(int size, int zero)
{
	char *print;

	if (!(print = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	print[size] = 0;
	if (zero)
		ft_memset(print, '0', size);
	else
		ft_memset(print, ' ', size);
	return (print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:05 by avieira           #+#    #+#             */
/*   Updated: 2020/01/23 07:05:29 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	def_conversion(const char *str)
{
	char		set[]="cspdiuxX%";
	int			i;

	str++;
	while (*str)
	{
		i = -1;
		while (set[++i])
			if (set[i] == *str)
				return (i);
		str++;
	}
	return (-1);
}

const char	*conversion(const char *str, va_list ap, int *ret)
{

	const char *	(*f[9])(const char*, va_list, int *);
	int				i;
	f[0] = &c;
	f[1] = &s;
	f[2] = &p;
	f[3] = &di;
	f[4] = &di;
	f[5] = &uxX;
	f[6] = &uxX;
	f[7] = &uxX;
	f[8] = &mod;
	if ((i = def_conversion(str)) != -1)
		return (f[i](str, ap, ret) + 1);
	write(1, "%", 1);  //Si conversion invalide, on l'ecrit raw
	va_arg(ap, char *);//Et on passe a l'argument suivant
	return (str + 1);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;
	int			i;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		i = 0;
		if (*str == '%')
			if (!(str = conversion(str, ap, &ret)))
				return (ret);
		while (str[i] && str[i] != '%')
			i++;
		if (i)
		{
			write(1, str, i);
			ret += i;
			str += i;
		}
	}
	va_end(ap);
	return (ret);
}

int main(void)
{
	int ret = printf("%3i", -100);
	printf("\nret = %d\n", ret);
	return (0);
}

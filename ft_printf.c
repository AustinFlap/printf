/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:05 by avieira           #+#    #+#             */
/*   Updated: 2020/01/28 05:27:02 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	def_conversion(const char *str)
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

static struct s_flag	def_flag(const char *str, char format, va_list ap)
{
	t_flag flag;

	flag.width = width(str, format, ap);
	flag.precision = precision(str, format, ap);
	flag.minus = minus(str, format);
	flag.zero = (flag.minus || ((format == 'd' || format == 'i' ||
		format == 'p') && flag.precision > -1)) ? 0 : zero(str, format);

	return (flag);
}

static const char	*conversion(const char *str, va_list ap, int *ret)
{
	void	(*f[9])(va_list, int*, t_flag);
	int				i;
	char set[]="cspdiuxX%";

	f[0] = &c;
	f[1] = &s;
	f[2] = &p;
	f[3] = &di;
	f[4] = &di;
	f[5] = &u;
	f[6] = &xX;
	f[7] = &xX;
	f[8] = &mod;
	if ((i = def_conversion(str)) != -1)
		f[i](ap, ret, def_flag(str, set[i], ap));
	str++;
	while (*str || *str == set[i])
		str++;
	return (str);
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
/*
int main(int ac, char **av)
{
	(void)ac;
	void *a;

	a = malloc(1);
	printf("PRINTF\n");
	

	int ret = printf(av[1], atoi(av[2]));
	

	printf("\nret = %d\n", ret);
	printf("\n\n");
	printf("FT_PRINTF\n");


	ret = ft_printf(av[1], atoi(av[2]));
	

	printf("\nret = %d\n", ret);
	printf("\n\n");
	free(a);
	return (0);
}*/

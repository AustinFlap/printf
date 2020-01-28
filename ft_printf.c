/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:05 by avieira           #+#    #+#             */
/*   Updated: 2020/01/28 19:17:46 by avieira          ###   ########.fr       */
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

static char		*get_arg(char format, va_list ap)
{
	char	*arg;

	if (format == 'c')
	{
		if (!(arg = ft_calloc(2, sizeof(char))))
			return (NULL);
		*arg = va_arg(ap, int);
		return (arg);
	}
	else if (format =='s')
		return (va_arg(ap, char *));
	else if (format == 'p')
		return (ft_convert_to_hex(va_arg(ap, unsigned long int), "0x"));
	else if (format == 'd' || format == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_itoa(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_convert_to_hex(va_arg(ap, unsigned int), ""));
	else if (format == '%')
		return ("%");
	return (NULL);
}

static struct s_flag	def_flag(const char *str, char format, va_list ap)
{
	t_flag flag;

	flag.width = width(str, format, ap);
	flag.precision = precision(str, format, ap);
	flag.minus = minus(str, format);
	flag.zero = (flag.minus || ((format == 'd' || format == 'i' ||
		format == 'p') && flag.precision > -1)) ? 0 : zero(str, format);
	flag.format = format;

	return (flag);
}

static const char	*conversion(const char *str, va_list ap, int *ret)
{
	void	(*f[9])(char*, int*, t_flag);
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
		f[i](get_arg(set[i], ap), ret, def_flag(str, set[i], ap));
	str++;
	while (*str && *str != set[i])
		str++;
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
			str = conversion(str, ap, &ret);
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
}
*/

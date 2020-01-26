/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:34 by avieira           #+#    #+#             */
/*   Updated: 2020/01/25 22:32:04 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		write_conversion(int *ret, char *arg, t_flag flag)
{
	int		size;
	int		len;
	char	*print;
	int		i;

	size = ft_strlen(arg);
	len = (size > flag.width) ? size : flag.width;
	if (!(print = alloc_print(len + 1, flag.zero)))
		return ;
	if (flag.minus)
		ft_memcpy(print, arg, size);
	else
		ft_memcpy(print + len - size, arg, size);
	i = 0;
	while (print[i] == '0')
		i++;
	if (print[i] == '-')
	{
		print[i] = '0';
		print[0] = '-';
	}
	write(1, print, len);
	*ret += len;
	free(print);
}

const char*		c(const char *str, va_list ap, int *ret, t_flag flag)
{
	char	*arg;

	if (!(arg = malloc(sizeof(char) * 2)))
		return (NULL);
	arg[0] = va_arg(ap, int);
	arg[1] = 0;
	write_conversion(ret, arg, flag);
	free(arg);
	while (*str && *str != 'c')
		str++;
	return (str);
}

const char*		s(const char *str, va_list ap, int *ret, t_flag flag)
{
	char	*arg;
	int		size;
	char	*s;

	arg = va_arg(ap, char *);
	size = ft_strlen(arg);
	size = (size > flag.precision && flag.precision != -1) ? flag.precision : size;
	if (!(s = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(s, arg, size + 1);
	s[size] = 0;
	write_conversion(ret, s, flag);
	free(s);
	while (*str && *str != 's')
		str++;
	return (str);
}

const char*	p(const char *str, va_list ap, int *ret, t_flag flag)
{
	char				*point;
	unsigned long int	r;

	r = va_arg(ap, unsigned long int);
	if (!(point = ft_convert_pointer(r)))
		return (NULL);
	write_conversion(ret, point, flag);
	free(point);
	while (*str && *str != 'p')
		str++;
	return (str);
}

const char*	di(const char *str, va_list ap, int *ret, t_flag flag)
{
	char	*nbr;
	int		size;
	int		neg;
	char	*n;

	if (!(nbr = ft_itoa(va_arg(ap, long int))))
		return (NULL);
	neg = (*nbr == '-') ? 1 : 0;
	size = ft_strlen(nbr) - neg;
	if (!(n = alloc_print(max(size, flag.precision) + neg, 1)))
		return (NULL);
	ft_memcpy(n + max(size, flag.precision) - size + neg, nbr + neg, size);
	if (neg)
		n[0] = '-';
	write_conversion(ret, n, flag);
	free(n);
	free(nbr);
	while (*str && *str != 'd' && *str != 'i')
		str++;
	return (str);
}

const char*	u(const char *str, va_list ap, int *ret, t_flag flag)
{
	(void)ap;
	(void)str;
	(void)ret;
	(void)flag;
	return (NULL);
}

const char*	xX(const char *str, va_list ap, int *ret, t_flag flag)
{
	(void)ap;
	(void)str;
	(void)ret;
	(void)flag;
	return (NULL);
}
const char*	mod(const char *str, va_list ap, int *ret, t_flag flag)
{
	(void)ap;
	(void)str;
	(void)flag;
	(void)ret;
	return (NULL);
}

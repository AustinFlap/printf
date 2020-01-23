/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:34 by avieira           #+#    #+#             */
/*   Updated: 2020/01/23 07:27:17 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

const char*		c(const char *str, va_list ap, int *ret)
{
	int		len;
	unsigned char *print;
	unsigned char arg;

	arg = va_arg(ap, int);
	len = width(str);
	if (len == -1)
		len = 1;
	if (!(print = alloc_print(len, 0)))
		return (NULL);
	if (minus(str))
		print[len - 1] = arg;
	else
		print[0] = arg;
	write(1, print, len);
	*ret += len;
	while (*str && *str != 'c')
		str++;
	return (str);
}

const char*		s(const char *str, va_list ap, int *ret)
{
	//RETRAIT DE ALLOC QUI PRENAIT LA VALEUR DE LEN
	int len;
	const char *arg;
	unsigned char *print;
	int size;

	arg = va_arg(ap, char *);
	len = width(str);
	size = ft_strlen(arg);
	if (precision(str) != -1 && size > precision(str))
		size = precision(str);
	if (len < size)
		len = size;
	if (!(print = alloc_print(len, 0)))
		return (NULL);
	if (!minus(str))
		ft_memcpy(print + len - size, arg, size);
	else
		ft_memcpy(print, arg, size);
	write(1, print, len);
	*ret += len;
	free(print);
	while (*str && *str != 's')
		str++;
	return (str);
}

const char*	p(const char *str, va_list ap, int *ret)
{
	unsigned char *print;
	char *point;
	unsigned long int r;
	int len;
	int size;

	r = va_arg(ap, unsigned long int);
	point = ft_convert_pointer(r);
	len = width(str);
	size = ft_strlen(point);
	if (len < size)
		len = size;
	if (!(print = alloc_print(len, 0)))
		return (NULL);
	if (!minus(str))
		ft_memcpy(print + len - size, point, size);
	else
		ft_memcpy(print, point, size);
	write(1, print, len);
	*ret += len;
	free(print);
	free(point);
	while (*str && *str != 'p')
		str++;
	return (str);
}

const char*	di(const char *str, va_list ap, int *ret)
{
	unsigned char *print;
	char *n;
	int len;
	int size;
	int neg;

	neg = 0;
	n = ft_itoa(va_arg(ap, long int));
	len = width(str);
	if (*n == '-')
		neg++;
	
	size = ft_strlen(n);
	if (len < size)
		len = size;
	if (!(print = alloc_print(len, zero(str))))
		return (NULL);
	
	(void)ret;
	(void)print;
	return (NULL);
}

const char*	uxX(const char *str, va_list ap, int *ret)
{
	(void)ap;
	(void)str;
	(void)ret;
	return (NULL);
}

const char*	mod(const char *str, va_list ap, int *ret)
{
	(void)ap;
	(void)str;
	(void)ret;
	return (NULL);
}

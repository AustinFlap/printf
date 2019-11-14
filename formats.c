/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:34 by avieira           #+#    #+#             */
/*   Updated: 2019/11/14 18:54:36 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		c(va_list ap, int *ret, int *flags)
{
	int		len;
	unsigned char *str;
	unsigned char arg;

	arg = va_arg(ap, int);
	len = 1;
	if (flags[0] > len)
		len = flags[0];
	str = ft_calloc(len + 1, sizeof(char));
	str[len] = 0;
	ft_memset(str, ' ', len);
	if (flags[2] < 0)
		str[len - 1] = arg;
	else
		str[0] = arg;
	write(1, str, len);
	*ret += len;
}
void		s(va_list ap, int *ret, int *flags)
{
	int len;
	const char *arg;
	unsigned char *str;
	int size;

	arg = va_arg(ap, char *);
	len = ft_strlen(arg);
	if (flags[0] > len)
		len = flags[0];
	str = ft_calloc(len + 1, sizeof(char));
	str[len] = 0;
	ft_memset(str, ' ', len);
	size = ft_strlen(arg);
	if (flags[1] < size && flags[1] != -1)
		size = flags[1];
	if (flags[2] < 0)
		ft_memcpy(str + len - size, arg, size);
	else
		ft_memcpy(str, arg, size);
	write(1,str, len);
	*ret += len;
}

void	p(va_list ap, int *ret, int *flags)
{
	(void)ap;
	(void)ret;
	(void)flags;
}

void	di(va_list ap, int *ret, int *flags)
{
	(void)ap;
	(void)ret;
	(void)flags;
}

void	uxX(va_list ap, int *ret, int *flags)
{
	(void)ap;
	(void)ret;
	(void)flags;
}

void	mod(va_list ap, int *ret, int *flags)
{
	(void)ap;
	(void)ret;
	(void)flags;
}

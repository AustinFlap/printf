/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:34 by avieira           #+#    #+#             */
/*   Updated: 2020/01/16 16:20:08 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		c(va_list ap, int *ret)
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
void		s(va_list ap, int *ret)
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
	free(str);
}

void	p(va_list ap, int *ret)
{
	char *point;
	unsigned long int r = va_arg(ap, unsigned long int);

	point = ft_convert_base(r, "0123456789", "0123456789abcdef");
	write(1, "0x", 2);
	write(1, point, ft_strlen(point));
	*ret += 2 + ft_strlen(point);
	
	(void)ap;
	(void)ret;
}

void	di(va_list ap, int *ret)
{
	(void)ap;
	(void)ret;
}

void	uxX(va_list ap, int *ret)
{
	(void)ap;
	(void)ret;
}

void	mod(va_list ap, int *ret)
{
	(void)ap;
	(void)ret;
}

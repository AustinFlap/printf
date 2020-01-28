/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:34 by avieira           #+#    #+#             */
/*   Updated: 2020/01/28 05:27:00 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*REARANGER/OPTIMISER FONCTIONS
 *MAJUSCULE X
 *%C AVEC CHAR = 0
 *%S AVEC STR = NULL
 *REPLACER SIGNE - (0x ?)
 */
void		write_conversion(int *ret, char *arg, t_flag flag)
{
	int		size;
	int		len;
	char	*print;

	size = ft_strlen(arg);
	len = (size > flag.width) ? size : flag.width;
	if (!(print = alloc_print(len + 1, flag.zero)))
		return ;
	if (flag.minus)
		ft_memcpy(print, arg, size);
	else
		ft_memcpy(print + len - size, arg, size);
	write(1, print, len);
	*ret += len;
	free(print);
}
//DECALER LE '-' au debut dans le cas d'un %d, a faire apres rangement de tout ce foutoir
void		c(va_list ap, int *ret, t_flag flag)
{
	char	*arg;

	if (!(arg = malloc(sizeof(char) * 2)))
		return ;
	arg[0] = va_arg(ap, int);
	arg[1] = 0;
	write_conversion(ret, arg, flag);
	free(arg);
}

void		s(va_list ap, int *ret, t_flag flag)
{
	char	*arg;
	int		size;
	char	*s;

	arg = va_arg(ap, char *);
	size = ft_strlen(arg);
	size = (size > flag.precision && flag.precision > -1) ? flag.precision : size;
	if (!(s = ft_calloc(size + 1, sizeof(char))))
		return ;
	ft_memcpy(s, arg, size);
	s[size] = 0;
	write_conversion(ret, s, flag);
	free(s);
}

void	p(va_list ap, int *ret, t_flag flag)
{
	char				*point;
	unsigned long int	r;
	int					size;
	char				*point2;

	r = va_arg(ap, unsigned long int);
	if (!(point = ft_convert_to_hex(r, "0x")))
		return ;
	size = ft_strlen(point) - 2;
	if (!(point2 = alloc_print(max(size, flag.precision) + 2, 1)))
		return ;
	ft_memcpy(point2 + max(size, flag.precision) - size + 2, point + 2, size);
	ft_memcpy(point2, "0x", 2);
	write_conversion(ret, point2, flag);
	free(point);
	free(point2);
}

void	di(va_list ap, int *ret, t_flag flag)
{
	char	*nbr;
	int		size;
	int		neg;
	char	*print;

	if (!(nbr = ft_itoa(va_arg(ap, int))))
		return ;
	neg = (*nbr == '-') ? 1 : 0;
	size = ft_strlen(nbr) - neg;
	if (!(print = alloc_print(max(size, flag.precision) + neg, 1)))
		return ;
	ft_memcpy(print + max(size, flag.precision) - size + neg, nbr + neg, size);
	if (neg)
		print[0] = '-';
	write_conversion(ret, print, flag);
	free(print);
	free(nbr);
}

void	u(va_list ap, int *ret, t_flag flag)
{
	char *nbr;
	int		size;
	char *print;

	if (!(nbr = ft_itoa(va_arg(ap, unsigned int))))
		return ;
	size = ft_strlen(nbr);
	if (!(print = alloc_print(max(size, flag.precision), 1)))
		return ;
	ft_memcpy(print + max(size, flag.precision) - size, nbr, size);
	write_conversion(ret, print, flag);
	free(nbr);
	free(print);
}

void	xX(va_list ap, int *ret, t_flag flag)
{
	char *hex;
	int size;
	char *print;

	if (!(hex = ft_convert_to_hex(va_arg(ap, unsigned int), "")))
		return ;
	size = ft_strlen(hex);
	if (!(print = alloc_print(max(size, flag.precision), 1)))
		return ;
	ft_memcpy(print + max(size, flag.precision) - size, hex, size);
	write_conversion(ret, print, flag);
	free(hex);
	free(print);
}
void		mod(va_list ap, int *ret, t_flag flag)
{
	char	*print;
	(void)ap;

	print = "%";
	write_conversion(ret, print, flag);
}


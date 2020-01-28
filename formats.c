/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:34 by avieira           #+#    #+#             */
/*   Updated: 2020/01/28 19:22:07 by avieira          ###   ########.fr       */
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
	if (flag.format == 'c' && *arg == 0)
		size++;
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
void		c(char *arg, int *ret, t_flag flag)
{
	write_conversion(ret, arg, flag);
	free(arg);
}

void		s(char *arg, int *ret, t_flag flag)
{
	int		size;
	char	*print;

	if (!arg)
	{
		write(1, "(null)", 6);
		*ret += 6;
		return ;
	}
	size = ft_strlen(arg);
	size = (size > flag.precision && flag.precision > -1) ? flag.precision : size;
	if (!(print = ft_calloc(size + 1, sizeof(char))))
		return ;
	ft_memcpy(print, arg, size);
	print[size] = 0;
	write_conversion(ret, print, flag);
	free(print);
}

void	p(char *arg, int *ret, t_flag flag)
{
	int					size;
	char				*print;

	size = ft_strlen(arg) - 2;
	if (!(print = alloc_print(max(size, flag.precision) + 2, 1)))
		return ;
	ft_memcpy(print + max(size, flag.precision) - size + 2, arg + 2, size);
	ft_memcpy(print, "0x", 2);
	write_conversion(ret, print, flag);
	free(print);
	free(arg);
}

void	di(char *arg, int *ret, t_flag flag)
{
	char	*print;
	int		size;
	int		neg;

	if (*arg == '0' && flag.precision == 0)
	{
		free(arg);
		write_conversion(ret, "", flag);
	}
	neg = (*arg == '-') ? 1 : 0;
	size = ft_strlen(arg) - neg;
	if (!(print = alloc_print(max(size, flag.precision) + neg, 1)))
		return ;
	ft_memcpy(print + max(size, flag.precision) - size + neg, arg + neg, size);
	if (neg)
		print[0] = '-';
	write_conversion(ret, print, flag);
	free(print);
	free(arg);
}

void	u(char *arg, int *ret, t_flag flag)
{
	int		size;
	char *print;

	size = ft_strlen(arg);
	if (!(print = alloc_print(max(size, flag.precision), 1)))
		return ;
	ft_memcpy(print + max(size, flag.precision) - size, arg, size);
	write_conversion(ret, print, flag);
	free(arg);
	free(print);
}

void	xX(char *arg, int *ret, t_flag flag)
{
	int size;
	char *print;

	size = ft_strlen(arg);
	if (!(print = alloc_print(max(size, flag.precision), 1)))
		return ;
	ft_memcpy(print + max(size, flag.precision) - size, arg, size);
	if (flag.format == 'X')
		str_toupper(print);
	write_conversion(ret, print, flag);
	free(arg);
	free(print);
}

void	mod(char *arg, int *ret, t_flag flag)
{
	write(1, arg, 1);
	(*ret)++;
	(void)flag;
}

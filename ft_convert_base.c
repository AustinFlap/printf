/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:02:46 by avieira           #+#    #+#             */
/*   Updated: 2019/11/15 14:36:46 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_create(unsigned long int number, unsigned int l_base_to, char **c_nbr)
{
	unsigned int l_number;

	l_number = 1;
	while (number >= l_base_to)
	{
		number /= l_base_to;
		l_number++;
	}
	if (!(*c_nbr = malloc(sizeof(char) * l_number)))
		return (0);
	return (l_number);
}

char	*ft_nbr_base(unsigned long int nbr, char *c_nbr, char *base_to, int l_number)
{
	unsigned long int	nb;
	int			i;
	unsigned int			l_base_to;

	l_base_to = 0;
	while (base_to[l_base_to])
		l_base_to++;
	i = 1;
	nb = nbr;
	while (nb >= l_base_to)
	{
		c_nbr[l_number - i] = base_to[nb % l_base_to];
		nb /= l_base_to;
		i++;
	}
	c_nbr[l_number - i] = base_to[nb % l_base_to];
	c_nbr[l_number] = '\0';
	return (c_nbr);
}
char	*ft_convert_base(unsigned long int point, char *base_from, char *base_to)
{
	unsigned long int	number;
	int			l_base_to;
	char		*c_nbr;
	int			l_number;
	(void)base_from;
	number = point;
	l_base_to = 0;
	while (base_to[l_base_to])
		l_base_to++;
	l_number = char_create(number, l_base_to, &c_nbr);
	c_nbr = ft_nbr_base(number, c_nbr, base_to, l_number);
	return (c_nbr);
}

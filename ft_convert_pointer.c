/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:02:46 by avieira           #+#    #+#             */
/*   Updated: 2020/01/23 06:21:36 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_create(unsigned long int nbr, unsigned int l_baseto, int *l_nbr)
{
	char *c_nbr;

	*l_nbr = 3;
	while (nbr >= l_baseto)
	{
		nbr /= l_baseto;
		(*l_nbr)++;
	}
	if (!(c_nbr = malloc(sizeof(char) * *l_nbr)))
		return (NULL);
	return (c_nbr);
}

char	*ft_nbr_base(unsigned long int nbr, char *c_nbr, int l_number)
{
	unsigned long int	nb;
	int			i;
	unsigned int			l_base_to;
	char *base_to;

	base_to = "0123456789abcdef";
	l_base_to = 16;
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
char	*ft_convert_pointer(unsigned long int point)
{
	int			l_base_to;
	char		*c_nbr;
	int			l_number;
	
	l_base_to = 16;
	c_nbr = char_create(point, l_base_to, &l_number);
	if (!(c_nbr))
		return (NULL);
	c_nbr = ft_nbr_base(point, c_nbr, l_number);
	c_nbr[0] = '0';
	c_nbr[1] = 'x';
	return (c_nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:03:29 by avieira           #+#    #+#             */
/*   Updated: 2020/01/28 19:06:49 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*char_create(unsigned long int nbr, unsigned int l_baseto, int *l_nbr, int l_prefix)
{
	char *c_nbr;

	*l_nbr = 1 + l_prefix;
	while (nbr >= l_baseto)
	{
		nbr /= l_baseto;
		(*l_nbr)++;
	}
	if (!(c_nbr = malloc(sizeof(char) * *l_nbr)))
		return (NULL);
	return (c_nbr);
}

static char	*ft_nbr_base(unsigned long int nbr, char *c_nbr, int l_number)
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

char	*ft_convert_to_hex(unsigned long int point, char *prefix)
{
	int			l_base_to;
	char		*c_nbr;
	int			l_number;
	int			l_prefix;

	l_prefix = ft_strlen(prefix);
	l_base_to = 16;
	c_nbr = char_create(point, l_base_to, &l_number, l_prefix);
	if (!(c_nbr))
		return (NULL);
	c_nbr = ft_nbr_base(point, c_nbr, l_number);
	ft_memcpy(c_nbr, prefix, l_prefix);
	return (c_nbr);
}

static int		get_lenght(long int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(long int n)
{
	long int	num;
	char		*number;
	int			len;

	num = n;
	num = (n < 0) ? num * -1 : num;
	len = get_lenght(n);
	if (!(number = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	number += len;
	*number = 0;
	while (num > 9)
	{
		*--number = num % 10 + 48;
		num /= 10;
	}
	*--number = num % 10 + 48;
	if (n < 0)
		*--number = '-';
	return (number);
}

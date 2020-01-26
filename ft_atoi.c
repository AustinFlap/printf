/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:44:21 by avieira           #+#    #+#             */
/*   Updated: 2020/01/25 19:02:31 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *nptr)
{
	int			nb;
	const char	*temp;
	int			u;

	u = 1;
	nb = 0;
	temp = nptr;
	while ((*temp >= 9 && *temp <= 13) || *temp == ' ')
		temp++;
	if (*temp == '-' || *temp == '+')
		temp++;
	while (*temp >= '0' && *temp <= '9')
		temp++;
	while ((temp != nptr) || ((*temp < 9 && *temp > 13) && *temp != ' '))
	{
		temp--;
		if (*temp >= '0' && *temp <= '9')
		{
			nb += (*temp - 48) * u;
			u *= 10;
		}
		else if (*temp == '-')
			nb *= -1;
	}
	return (nb);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

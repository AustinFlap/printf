/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:23:52 by avieira           #+#    #+#             */
/*   Updated: 2019/11/14 16:51:31 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char				*alloc;
	size_t				i;

	if (!(alloc = malloc(size * count)))
		return (NULL);
	i = 0;
	while (i < count * size)
		alloc[i++] = 0;
	return (alloc);
}

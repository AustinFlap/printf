/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:03:29 by avieira           #+#    #+#             */
/*   Updated: 2020/01/25 03:03:33 by avieira          ###   ########.fr       */
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

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*t_dst;
	const unsigned char	*t_src;

	t_dst = dst;
	t_src = src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*t_dst++ = *t_src++;
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *temp;
	unsigned char d;

	d = c;
	temp = b;
	while (len--)
		*temp++ = d;
	return (b);
}

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}


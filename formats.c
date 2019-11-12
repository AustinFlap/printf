/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:34 by avieira           #+#    #+#             */
/*   Updated: 2019/11/12 17:07:10 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		c(va_list ap, int *ret, int *flags)
{
	unsigned char c;
	(void)flags;
	c = va_arg(ap, int);
	write(1, &c, 1);
	ret++;
}

void		s(va_list ap, int *ret, int *flags)
{
	char *s;

}

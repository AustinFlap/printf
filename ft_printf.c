/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:05 by avieira           #+#    #+#             */
/*   Updated: 2019/11/14 18:53:49 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	init_f(void (*f[9])(va_list, int *, int *))
{
	f[0] = &c;
	f[1] = &s;
	f[2] = &p;
	f[3] = &di;
	f[4] = &di;
	f[5] = &uxX;
	f[6] = &uxX;
	f[7] = &uxX;
	f[8] = &mod;
}

const char	*write_conversion(const char *str, va_list ap, int *ret, int *flags)
{

	char		set[]="cspdiuxX%";
	void		(*f[9])(va_list, int *, int *);
	int			i;
	printf("\nFLAGS : %d, %d, %d\n", flags[0], flags[1], flags[2]);
	init_f(f);
	i = -1;
	while (set[++i])
		if (set[i] == *str)
			f[i](ap, ret, flags);
	return (str);
}

const char	*read_flags(const char *str, va_list ap, int *ret)
{

	int			flags[]= {-1,-1,0}; //min_width, max_width, fill (defaut = 0, - => < 0, 0 => > 0)
	int			i;

	str++;
	while (*str)
	{
		i = 0;
		if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' || 
			*str == 'i' || *str == 'u' || *str == 'x' || *str == 'X' ||
			*str == '%')
			return (write_conversion(str, ap, ret, flags));
		flags[2] = ((*str == '-' || *str == '0') && *(str - 1) == '%') ? *str++ - 46 : flags[2];
		if (*str == '.' && ft_isdigit(*(str + 1)))
		{
			str++;
			i++;
		}
		flags[i] = (ft_isdigit(*str) && flags[i] == -1) ? ft_atoi(str) : flags[i];
		while(ft_isdigit(*(str + 1)))
			str++;
		str++;
	}
	return (str);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			str = read_flags(str, ap, &ret);
		else
		{
			write(1, &(*str), 1);
			ret++;
		}
		str++;
	}
	va_end(ap);
	return (ret);
}

int main(void)
{
	int ret = printf("%*s", 8, "allo");
	printf("\nret = %d\n", ret);
	return (0);
}

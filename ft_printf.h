/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:12:37 by avieira           #+#    #+#             */
/*   Updated: 2020/01/16 16:32:44 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

const char *	c(va_list ap, int *ret);
const char *	s(va_list ap, int *ret);
const char *	p(va_list ap, int *ret);
const char *	di(va_list ap, int *ret);
const char *	uxX(va_list ap, int *ret);
const char *	mod(va_list ap, int *ret);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_itoa(int n);
char *ft_convert_base(unsigned long int, char*, char*);

#endif

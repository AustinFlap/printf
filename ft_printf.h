/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:12:37 by avieira           #+#    #+#             */
/*   Updated: 2020/01/23 07:27:25 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

unsigned char *		alloc_print(int, int);
const char *	c(const char *str, va_list ap, int *ret);
const char *	s(const char *str, va_list ap, int *ret);
const char *	p(const char *str, va_list ap, int *ret);
const char *	di(const char *str, va_list ap, int *ret);
const char *	uxX(const char *str, va_list ap, int *ret);
const char *	mod(const char *str, va_list ap, int *ret);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_itoa(int n);
char *ft_convert_pointer(unsigned long int);
int		width(const char*);
int		precision(const char*);
int		zero(const char*);
int		minus(const char*);
#endif

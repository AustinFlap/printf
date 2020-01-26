/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:12:37 by avieira           #+#    #+#             */
/*   Updated: 2020/01/25 22:31:05 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

typedef struct	s_flag
{
	int width;
	int precision;
	int zero;
	int minus;
}				t_flag;



int		max(int a, int b);
void		write_conversion(int*, char*, t_flag);
char *		alloc_print(int, int);
const char *	c(const char*, va_list, int*, t_flag);
const char *	s(const char*, va_list, int*, t_flag);
const char *	p(const char*, va_list, int*, t_flag);
const char *	di(const char*, va_list, int*, t_flag);
const char *	u(const char*, va_list, int*, t_flag);
const char *	xX(const char*, va_list, int*, t_flag);
const char *	mod(const char*, va_list, int*, t_flag);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_itoa(long int n);
char	*ft_convert_pointer(unsigned long int);
int		width(const char*);
int		precision(const char*);
int		zero(const char*);
int		minus(const char*);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:12:37 by avieira           #+#    #+#             */
/*   Updated: 2020/01/28 18:36:52 by avieira          ###   ########.fr       */
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
	char format;
}				t_flag;


void		str_toupper(char *str);
void		place_front(char*, char);
int		max(int a, int b);
void		write_conversion(int*, char*, t_flag);
char *		alloc_print(int, int);
void 	c(char *, int*, t_flag);
void 	s(char *, int*, t_flag);
void 	p(char *, int*, t_flag);
void 	di(char *, int*, t_flag);
void 	u(char *, int*, t_flag);
void 	xX(char *, int*, t_flag);
void 	mod(char *, int*, t_flag);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_itoa(long int n);
char	*ft_convert_to_hex(unsigned long int, char*);
int		width(const char*, char, va_list);
int		precision(const char*, char, va_list);
int		zero(const char*, char);
int		minus(const char*, char);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:37:20 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/18 14:28:58 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct		s_list
{
	int		minus;
	int		zero;
	int		star;
	int		dot;
	int		width;
	int		precision;
}					t_list;

size_t				ft_strlen(const char *s);
int					ft_printf(const char *string, ...);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strdup(char *s1);
char				*ft_itoa(int n);
char				*make_str(char c);
int					ft_atoi(const char *str, int *cnt);
int					is_max(int a, int b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:39:09 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/20 11:47:16 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t move;

	move = 0;
	while (s[move])
		move++;
	return (move);
}

void		ft_putstr(char *s)
{
	while(*s)
	{
		write(1, s, sizeof(char));
		s++;
	}
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	int		move;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	move = 0;
	while (s1[move])
	{
		dup[move] = s1[move];
		move++;
	}
	dup[move] = '\0';
	return (dup);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			move;
	unsigned char	tmp;
	unsigned char	*src;

	src = (unsigned char *)b;
	tmp = (unsigned char)c;
	move = 0;
	while (move < len)
	{
		src[move] = tmp;
		move++;
	}
	return (b);
}

int				ft_atoi(const char *str, int *cnt)
{
	long	sol;
	char	*tmp;

	tmp = (char *)str;
	sol = 0;
	while (*tmp >= '0' && *tmp <= '9')
	{
		sol = (sol * 10) + (*tmp - '0');
		tmp++;
		if (sol > 2147483647)
			return (-1);
		if (sol < -2147483648)
			return (-1);
		(*cnt)++;
	}
	return ((int)sol);
}

int			is_max(int a, int b)
{
	if(a>b)
		return (a);
	return(b);
}

static	int		find_size(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static	void	input_data(long n, char *sol, int size, int start)
{
	int		tmp;

	while (size >= start)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp *= -1;
		n /= 10;
		sol[size] = tmp + '0';
		size--;
	}
}

char			*ft_itoa(int n)
{
	char	*sol;
	int		size;
	int		start;

	size = find_size(n);
	if (n < 0)
		size++;
	if (!(sol = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
	{
		start = 1;
		sol[0] = '-';
	}
	else
		start = 0;
	input_data(n, sol, size - 1, start);
	sol[size] = '\0';
	return (sol);
}

char *make_str(char c)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * 2);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

int		is_in(char *s, char c)
{
	int move;

	move = 0;
	while (s[move])
	{
		if (c == s[move])
			return (move);
		move++;
	}
	return (-1);
}

void	upper_string(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s += 'A' - 'a';
		s++;
	}
}

char	*go_to_hex(long dummy, int cnt, long tmp, int up)
{
	char	*str;
	int		move;
	char	*hex = "0123456789abcdef";

	cnt = 0;
	tmp = dummy;
	while (tmp)
	{
		tmp/=16;
		cnt++;
	}
	move = cnt;
	if (!(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (0);
	str[cnt] = '\0';
	while (--move >= 0)
	{
		str[move] = hex[dummy % 16];
		dummy/= 16;
	}
	if (up)
		upper_string(str);
	return (str);
}

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy(&join[s1_len], s2, s2_len + 1);
	free(s2);
	return (join);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

static	int		find_usize(long n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_uitoa(long n)
{
	char	*sol;
	int		size;
	int		start;

	if (n < 0)
		n = 4284967296;
	size = find_usize(n);
	if (!(sol = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	start = 0;
	input_data(n, sol, size - 1, start);
	sol[size] = '\0';
	return (sol);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:40:32 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/12 09:59:13 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isdigit(int c)
{
	unsigned char	tmp;

	tmp = (unsigned char)c;
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

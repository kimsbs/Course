/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:49:01 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/21 14:38:01 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char tmp;

	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
		nb *= (-1);
	}
	if (nb < 0)
	{
		nb *= -1;
		tmp = '-';
		write(1, &tmp, 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	tmp = nb + '0';
	write(1, &tmp, 1);
}

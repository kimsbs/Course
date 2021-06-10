/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:03:42 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 21:08:24 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	swap_element(t_list **header)
{
	int		tmp;

	if(*header && (*header)->next != *header)
	{
		tmp = (*header)->index;
		(*header)->index = (*header)->next->index;
		(*header)->next->index = tmp;
	}
}

void	swap_a(t_list **a)
{
	swap_element(a);
}

void	swap_b(t_list **b)
{
	swap_element(b);
}

void	swap_s(t_list **a, t_list **b)
{
	swap_a(a);
	swap_b(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:31:07 by ksy               #+#    #+#             */
/*   Updated: 2022/02/11 01:19:10 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	diff_time(struct timeval before, struct timeval after)
{
	int	diff;

	diff = 0;
	diff += after.tv_sec - before.tv_sec;
	diff *= 1000000;
	diff += after.tv_usec - before.tv_usec;
	return (diff / 1000);
}

void	sleep_and_think(t_philo *philo, int index, int flag)
{
	if (!any_dead(philo->data))
	{
		if (flag == 1)
			ft_print_time(philo, index, "sleeping");
		else
			ft_print_time(philo, index, "thinking");
		if (!philo->data->dead && flag == 1)
		{
			ft_usleep(philo->data->info->time_to_sleep);
			sleep_and_think(philo, philo->index, 0);
		}
	}
}

void	eating(t_philo *philo, int index)
{
	int	right_pos;

	right_pos = (index + 1) % philo->data->info->num_of_philo;
	if (!any_dead(philo->data))
	{
		philo->last_meal = philo->data->cur;
		ft_print_time(philo, index, "eating");
		if (!any_dead(philo->data))
		{
			ft_usleep(philo->data->info->time_to_eat);
			philo->last_meal = philo->data->cur;
		}
		philo->data->cnt[index] += 1;
		philo->left_fork = 0;
		philo->right_fork = 0;
		pthread_mutex_unlock(&philo->data->fork[index]);
		pthread_mutex_unlock(&philo->data->fork[right_pos]);
		sleep_and_think(philo, philo->index, 1);
	}
}

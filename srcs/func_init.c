/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:50:55 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/16 17:50:57 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*get_xpm_ptr(t_game *game, char *str)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, str,
			&(game->dummy.w), &(game->dummy.h));
	if (!img)
		exit_handler("xpm error\n");
	return (img);
}

void	img_init(t_game *game)
{
	game->link.coin.ptr = get_xpm_ptr(game, "./img/coin.xpm");
	game->link.exit.ptr = get_xpm_ptr(game, "./img/exit.xpm");
	game->link.tile.ptr = get_xpm_ptr(game, "./img/tile.xpm");
	game->link.tree.ptr = get_xpm_ptr(game, "./img/tree.xpm");
	game->link.pd[0].ptr = get_xpm_ptr(game, "./img/pd0.xpm");
	game->link.pd[1].ptr = get_xpm_ptr(game, "./img/pd1.xpm");
	game->link.pd[2].ptr = get_xpm_ptr(game, "./img/pd2.xpm");
	game->link.pu[0].ptr = get_xpm_ptr(game, "./img/pu0.xpm");
	game->link.pu[1].ptr = get_xpm_ptr(game, "./img/pu1.xpm");
	game->link.pu[2].ptr = get_xpm_ptr(game, "./img/pu2.xpm");
	game->link.pl[0].ptr = get_xpm_ptr(game, "./img/pl0.xpm");
	game->link.pl[1].ptr = get_xpm_ptr(game, "./img/pl1.xpm");
	game->link.pr[0].ptr = get_xpm_ptr(game, "./img/pr0.xpm");
	game->link.pr[1].ptr = get_xpm_ptr(game, "./img/pr1.xpm");
	game->player = game->link.pd[1];
	game->animation = 0;
	game->move_cnt = 0;
}

void	enemy_init(t_game *game)
{
	game->link.enemy[0].ptr = get_xpm_ptr(game, "./img/e_d.xpm");
	game->link.enemy[1].ptr = get_xpm_ptr(game, "./img/e_l.xpm");
	game->link.enemy[2].ptr = get_xpm_ptr(game, "./img/e_u.xpm");
	game->link.enemy[3].ptr = get_xpm_ptr(game, "./img/e_r.xpm");
	game->enemy.ptr = game->link.enemy[0].ptr;
}

void	resource_init(t_game *game)
{
	img_init(game);
	enemy_init(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:18:52 by xlongfel          #+#    #+#             */
/*   Updated: 2020/03/02 16:18:53 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift(int key, t_mlx *m)
{
	if (key == UP)
	{
		m->coor.min_y += 0.4;
		m->coor.max_y += 0.4;
	}
	else if (key == DOWN)
	{
		m->coor.min_y -= 0.4;
		m->coor.max_y -= 0.4;
	}
	else if (key == LEFT)
	{
		m->coor.min_x += 0.4;
		m->coor.max_x += 0.4;
	}
	else if (key == RIGHT)
	{
		m->coor.min_x -= 0.4;
		m->coor.max_x -= 0.4;
	}
}

int		deal_key(int key, t_mlx *m)
{
	if (key == ESCAPE)
		exit(0);
	else if (key == KEY_P)
		m->julia.pause = !m->julia.pause;
	else if (key == KEY_R)
		setup(m);
	else if (key == KEY_C)
		switch_colorset(m);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		shift(key, m);
	else if (key == MINUS)
		m->max_iter = m->max_iter + 4;
	else if (key == PLUS)
		m->max_iter = m->max_iter - 4;
	else if (key == ONE || key == TWO || key == THREE || key == FOUR)
		m->mode_num = key - ONE;
	else if (key == KEY_I)
		m->hide = 0;
	draw(m);
	return (0);
}

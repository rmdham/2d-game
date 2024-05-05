/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_anime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:28:25 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/05 11:29:14 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_anime(t_map *d)
{
	if (d->c != 0)
		IMAGE(d->mlx_ptr, d->wind, d->exit_pic, d->y * TW, d->x
			* TH);
	else
		IMAGE(d->mlx_ptr, d->wind, d->exit1_pic, d->y * TW, d->x
			* TH);
}

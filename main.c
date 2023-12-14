/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:03 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/14 10:56:42 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_x_size(t_mapset	mapset, char *str)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != '\n')
	{
		count++;
	}
	mapset.x_size = count;
}

void	launch(char *plateau_str)
{
	t_mapset	mapset;
	int			i;
	int			**maped;

	if (!plateau_str)
		return ;
	get_x_size(mapset, plateau_str);
	maped = map(plateau_str, mapset);
	if (!maped)
		return ;
	maped = init_carr(maped, mapset);
	write_carr(maped, mapset);
	free(plateau_str);
	if (maped)
	{
		i = 0;
		while (i < mapset.y_size)
		{
			free(maped[i]);
			i++;
		}
		free(maped);
	}
}

int	main(int argc, char **argv)
{
	char	*plateau_str;

	
	plateau_str = str_file(argv[1]);
	if (!plateau_str)
		return (1);
	launch(plateau_str);
}

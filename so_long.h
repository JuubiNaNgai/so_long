/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:36:22 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/11 14:34:50 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mapset
{
	int		x_size;
	int		y_size;
	char	**map;
}	t_mapset;


void	launch(char *plateau_str);

#endif
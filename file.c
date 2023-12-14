/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:07:25 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/11 14:36:15 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_size(char *argv)
{
	int		file;
	int		size;
	char	c;

	size = 0;
	file = open(argv, O_RDONLY);
	if (file < 0)
	{
		ft_putstr("map error\n", 2);
		return (-1);
	}
	while (read(file, &c, 1) > 0)
		size++;
	if (read(file, &c, 1) < 0)
	{
		write(1, "map error\n", 2);
		return (-1);
	}
	close(file);
	return (size);
}

char	*str_file(char *path)
{
	int		size_of_file;
	int		file;
	char	*buff;
	int		i;

	i = 0;
	size_of_file = file_size(path);
	if (size_of_file < 6)
	{
		if (size_of_file != -1)
			write(1, "map error\n", 11);
		return (NULL);
	}
	buff = malloc(sizeof(char) * (size_of_file + 1));
	if (!buff)
		return (NULL);
	file = open(path, O_RDONLY);
	if (read(file, buff, size_of_file) > 0)
	{
		buff[size_of_file] = '\0';
		return (buff);
	}
	else
		write(1, "map error\n", 11);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:17:49 by mvisca            #+#    #+#             */
/*   Updated: 2023/09/14 13:23:50 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char		**sl_load_map(char *filename, t_game *g);
static char	*sl_read_fd(int fd, t_game *g);
int			sl_get_map_xy(char *info, int option, t_game *g);
static char	**sl_valid_file(char *str_map, int fd, t_game *g);

t_map	*sl_map_init(char *filename, t_game *g)
{
	g->map = (t_map *) malloc (sizeof(t_map));
	if (!g->map)
		error_and_exit(TRUE, "Map alloc error\n", g);
	g->map->tiles = sl_load_map(filename, g);
	if (!g->map->tiles)
		error_and_exit(TRUE, "Map load error\n", g);
	g->map->r = sl_get_map_xy("rows", 1, g);
	g->map->c = sl_get_map_xy("cols", 0, g);
	g->map = sl_map_validate(g);
	return (g->map);
}

char	**sl_load_map(char *filename, t_game *g)
{
	int		fd;
	char	*str_map;
	char	**res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Open file error\n");
		exit(EXIT_FAILURE);
	}
	str_map = sl_read_fd(fd, g);
	if (str_map[0] != '1')
	{
		close(fd);
		g->map = NULL;
		error_and_exit(TRUE, "Map content error\n", g);
	}
	res = sl_valid_file(str_map, fd, g);
	close (fd);
	free(str_map);
	return (res);
}

static char	**sl_valid_file(char *str_map, int fd, t_game *g)
{
	int		i;

	i = 0;
	if (str_map[0] == 0 || str_map[0] == '\n')
	{
		close(fd);
		g->map = NULL;
		error_and_exit(TRUE, "Map content error\n", g);
	}
	while (str_map[i] && str_map[i + 1])
	{
		if (str_map[i] == '\n' && str_map[i + 1] == '\n')
		{
			close(fd);
			g->map = NULL;
			error_and_exit(TRUE, "Map content error\n", g);
		}
		i++;
	}
	return (ft_split(str_map, '\n'));
}

static char	*sl_read_fd(int fd, t_game *g)
{
	char	buffer[101];
	int		bytes_read;
	char	*str_map;
	char	*aux;

	buffer[100] = '\0';
	bytes_read = 1;
	str_map = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 100);
		if (bytes_read < 0)
			error_and_exit(TRUE, "Read file error\n", g);
		buffer[bytes_read] = '\0';
		aux = str_map;
		str_map = ft_strjoin(str_map, buffer);
		free(aux);
		if (!str_map)
			error_and_exit(TRUE, "Read file error\n", g);
	}
	return (str_map);
}

int	sl_get_map_xy(char *info, int option, t_game *g)
{
	int	rows;
	int	cols;

	(void)info;
	if (option)
	{
		rows = 0;
		while (g->map->tiles[rows])
			rows++;
		return (rows);
	}
	cols = ft_strlen(g->map->tiles[0]);
	return (cols);
}

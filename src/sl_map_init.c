/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:17:49 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/24 14:18:38 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**sl_load_map(char *filename, t_game *g);
int     sl_get_map_xy(char *info, int option, t_game *g);

t_map   *sl_map_init(char *filename, t_game *g)
{
    g->map = (t_map *) malloc (sizeof(t_map));
    if (!g->map)
        error_and_exit(TRUE, "Error allocating map", g);
    g->map->tiles = sl_load_map(filename, g);
	int aa = 0;
	ft_printf("Ini\n");
	while (aa < g->map->r)
		ft_printf("%s", g->map[aa++]);
	ft_printf("Fin\n");
    if (!g->map->tiles)
        error_and_exit(TRUE, "Error loading map", g);
    g->map->r = sl_get_map_xy("rows", 1, g);
    g->map->c = sl_get_map_xy("cols", 0, g);
    return (g->map);
}

char	**sl_load_map(char *filename, t_game *g)
{
	char	buffer[101];
	int		bytes_read;
	char	*str_map;
	char	*aux;
	int		fd;
	char	**test;

	buffer[100] = '\0';
	bytes_read = 1;
	str_map = ft_strdup("");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_and_exit(TRUE, "Error opening file", g);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 100);
		if (bytes_read < 0)
			error_and_exit(TRUE, "Error reading file", g);
		buffer[bytes_read] = '\0';
		aux = str_map;
		str_map = ft_strjoin(str_map, buffer);
		free(aux);
		if (!str_map)
			error_and_exit(TRUE, "Error reading file", g);
	}
	close (fd);
	test = ft_split(str_map, '\n');
	int aa = 0;
	ft_printf("Ini2\n");
	while (test[aa])
		ft_printf("%s\n", test[aa++]);
	ft_printf("Fin2\n");
	ft_printf("Ini3\n");
		ft_printf("%s\n", test[2]);
	ft_printf("Fin3\n");


	return (ft_split(str_map, '\n'));
}

int     sl_get_map_xy(char *info, int option, t_game *g)
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
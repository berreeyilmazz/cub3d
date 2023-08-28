/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:49:21 by havyilma          #+#    #+#             */
/*   Updated: 2023/08/28 22:15:44 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_map *map)
{
	map->north_text = NULL;
	map->south_text = NULL;
	map->west_text = NULL;
	map->east_text = NULL;
	map->map = NULL;
}

int	check_map_name(char *av1)
{
	int	i;

	i = ft_strlen(av1);
	if (i <= 4)
		return (1);
	i--;
	if (!(av1[i] == 'b' && av1[i - 1] == 'u' && av1[i - 2] == 'c' && av1[i - 3] == '.'))
		return (1);
	return (0);
}

int	fill_them(char *str, int *i, int type, t_map *map)
{
	int	finish;

	*i += 2;
	while (str[*i] == 32)
		(*i)++;
	finish = *i;
	while (str[finish] != '\0' && str[finish] != '\n')
		finish++;
	if (type == 'N')
		map->north_text = ft_substr(str, *i, finish);
	else if (type == 'S')
		map->south_text = ft_substr(str, *i, finish);
	else if (type == 'W')
		map->west_text = ft_substr(str, *i, finish);
	else if (type == 'E')
		map->east_text = ft_substr(str, *i, finish);
	while (str[finish] == 32)
		finish++;
	if (str[finish] != '\n' && str[finish] != '\0')
		return (1);
	return (0);
}

void	fill_c(t_map *map, int *i, int finish, char *str)
{
	char	*number;

	number = ft_substr(str, *i, finish);
	map->rgb_c[0] = ft_atoi(number);
	free (number);
}

int	fill_intpointr(char *str, int *i, int type, t_map *map)
{
	int		finish;
	int		rgb;
	char	*number;
	
	rgb = 0;
	*i += 1;
	while (str[*i] == 32)
		(*i)++;
	finish = *i;
	while (str[finish] && rgb < 3)
	{
		*i = finish;
		while (str[finish] >= 48 && str[finish] <= 57)
			finish++;
		if (*i == finish)
			return (1);
		if (type == 'C')
		{
			number = ft_substr(str, *i, finish);
			printf("aa\n");
			map->rgb_c[rgb] = ft_atoi(number);
			printf("b\n");
			free (number);
		}
		else if (type == 'F')
		{
			number = ft_substr(str, *i, finish);
			map->rgb_f[rgb] = ft_atoi(number);
			free (number);
		}
		rgb += 1;
	}
	return (0);
}

int	take_texts(char *str, t_map *map)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	if (str[0] == '\n')
		return (0);
	while (str[i])
	{
		if (str[i] && str[i + 1] && str[i] == 'N' && str[i + 1] == 'O')
			flg = fill_them(str, &i, 'N', map);
		else if (str[i] && str[i + 1] && str[i] == 'S' && str[i + 1] == 'O')
			flg = fill_them(str, &i, 'S', map);
		else if (str[i] && str[i + 1] && str[i] == 'W' && str[i + 1] == 'O')
			flg = fill_them(str, &i, 'W', map);
		else if (str[i] && str[i + 1] && str[i] == 'N' && str[i + 1] == 'O')
			flg = fill_them(str, &i, 'E', map);
		else if (str[i] && str[i] == 'F')
			flg = fill_intpointr(str, &i, 'F', map);
		else if (str[i] && str[i] == 'C')
			flg = fill_intpointr(str, &i, 'C', map);
		else if (str[i] == ' ')
			i++;
	}
	if (flg == 1)
		return (0);
	return (0);
}

int	check_if_them_full(t_map *map)
{
	if (map->north_text == NULL 
		|| map->south_text == NULL
		|| map->west_text == NULL
		|| map->east_text == NULL)
		return (1);
	return (0);
}

int	textures(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	fd = open(path, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		return (1);
	while (tmp)
	{
		i++;
		if (tmp[0] != '\n')
		{
			if (take_texts(tmp, map))
			{
				free (tmp);
				return (1);
			}
		}
		free (tmp);
		tmp = get_next_line(fd);
	}
	if (check_if_them_full(map))
		return (1);
	return (i);
}

void	ft_free_str(t_map *map)
{
	if (map->north_text)
		free (map->north_text);
	if (map->south_text)
		free (map->south_text);
	if (map->west_text)
		free (map->west_text);
	if (map->east_text)
		free (map->east_text);
}


int	check_map(int ac, char *av1)
{
	t_map	map;
	if (ac != 2)
		return (1);
	if (check_map_name(av1) == 1)
		return (1);
	ft_init(&map);
	if (textures(av1, &map) == 1)
	{
		ft_free_str(&map);
	printf("aa\n");
		return (1);
	}
	printf("%s\n%s\n%s\n%s\n", map.north_text, map.south_text, map.west_text, map.east_text);
	return (0);
}

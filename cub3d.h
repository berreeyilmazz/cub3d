/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:15:30 by havyilma          #+#    #+#             */
/*   Updated: 2023/08/28 22:09:10 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H

#define CUB3D_H

#include <math.h>
#include "get_next_line/get_next_line.h"
#include "minilibx/mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_map
{
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
	char	**map;
	int		ply_x;
	int		ply_y;
	int		length;
	int		*rgb_c;
	int		*rgb_f;
}				t_map;

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		check_map(int ac, char *av1);
int	ft_atoi(const char *str);

#endif


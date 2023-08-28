/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:43:01 by havyilma          #+#    #+#             */
/*   Updated: 2023/08/28 22:07:15 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Created: 2022/10/09 18:25:25 by havyilma          #+#    #+#             */
/*   Updated: 2022/10/11 01:44:04 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
//	if (start >= ft_strlen(s))
//		return (ft_strdup(""));
//	if (len > ft_strlen(s) - start)
//		len = ft_strlen(s) - start;
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	while (s[start] && len != 0)
	{
		a[i] = s[start];
		i++;
		start++;
		len--;
	}
	a[i] = 0;
	return (a);
}

int	ft_atoi(const char *str)
{
	long		i;
	long		sign;
	long		result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + str[i] - 48;
		i++;
		if (result * sign > 2147483647)
			return (-1);
		if (result * sign < -2147483648)
			return (0);
	}
	return (result * sign);
}
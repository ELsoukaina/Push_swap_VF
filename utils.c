/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:40:56 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/24 23:36:06 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (lensrc);
	while (dstsize - 1 > i && lensrc > 0)
	{
		dst[i] = src[i];
		i++;
		lensrc--;
	}
	dst[i] = '\0';
	return (lensrc + i);
}

int	ft_isdigit(int d)
{
	if (d >= 48 && d <= 57)
		return (1);
	return (0);
}

void	minmax(long int res, int sign)
{
	res = sign * res;
	if (res > 2147483647 || res < -2147483648)
		print_error();
}

int	ft_atoi(const char *str)
{
	long int	i[3];

	i[0] = 0;
	i[1] = 1;
	i[2] = 0;
	while (str[i[0]] == ' ' || str[i[0]] == '\f' || str[i[0]] == '\t'
		|| str[i[0]] == '\v' || str[i[0]] == '\n' || str[i[0]] == '\r')
		i[0]++;
	if (str[i[0]] == '-')
		i[1] = -1;
	if ((str[i[0]] == '+' || str[i[0]] == '-') && str[i[0] + 1] == '\0')
		print_error();
	else if (str[i[0]] == '+' || str[i[0]] == '-')
		i[0]++;
	while (str[i[0]] != '\0')
	{
		if (ft_isdigit(str[i[0]]) == 0)
			print_error();
		i[2] = i[2] * 10 + str[i[0]] - '0';
		i[0]++;
	}
	minmax(i[2], i[1]);
	return (i[2] * i[1]);
}

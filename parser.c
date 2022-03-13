/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:33:12 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/13 15:55:35 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prevalid(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (!ft_otoi(str++))
		{
			ft_error();
		}
	}
	return (1);
}

void	validation(t_parse *parse)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (parse->big_str[i])
	{
		if (prevalid(parse->big_str[i]) == 0)
		{
			flag = 0;
			break ;
		}
		i++;
	}
	if (flag == 0)
		ft_error();
}

int	words(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	duplicates(t_parse *parse)
{
	int	i;
	int	flag;
	int	c;

	i = 0;
	flag = -1;
	c = parse->array[i];
	while (i < parse->size)
	{
		if (parse->array[i] == c)
			flag++;
		else
		{
			c = parse->array[i];
			flag = 0;
		}
		if (flag > 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

int	*create_ind_array(int len)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
	{
		printf("no ind_array!\n");
		exit(0);
	}
	while (i < len)
	{
		arr[i] = i + 1;
		i++;
	}
	return (arr);
}

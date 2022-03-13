/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:26:56 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/13 16:00:30 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	output(char **str)
{
	while (*str)
		printf("%s ",*str++);
	write(1, "\n", 1);
}

void	writearray(t_parse *parse)
{
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (i < parse->size)
	{
		ft_putnbr_fd(parse->array[i], 0);
		write(0, " ", 1);
		i++;
	}
}

void	printmassiv(int *A)
{
	int	i;

	i = 0;
	printf("\n");
	while (A[i])
	{
		ft_putnbr_fd(A[i], 0);
		write(0, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	atoi_checker(char *str, int sign)
{
	long	mod;

	mod = 0;
	if (*str < '0' || *str > '9')
		ft_error();
	while (*str && *str >= '0' && *str <= '9')
	{
		if (mod * sign > 2147483647 || mod * sign < -2147483648)
			ft_error();
		mod = mod * 10 + *str++ - '0';
	}
	if (mod * sign > 2147483647 || mod * sign < -2147483648)
		ft_error();
}

int	ft_otoi(char *str)
{
	int	mod;
	int	sign;

	sign = 1;
	mod = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	atoi_checker(str, sign);
	while (*str && *str >= '0' && *str <= '9')
		mod = mod * 10 + *str++ - '0';
	if (*str != 0 && !(*str >= '0' && *str <= '9'))
		ft_error();
	return (mod * sign);
}

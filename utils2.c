/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:00:05 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/14 13:51:06 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	issorted(t_stack *a)
{
	t_node	*kek;
	int		flag;

	flag = 0;
	kek = a->head;
	if (kek->value > kek->next->value)
		sa_sb(a,1);
}
int isis(t_stack *a)
{
	t_node	*kek;
	int		flag;

	flag = 0;
	kek = a->head;
	while (kek->next)
	{
		if (kek->value > kek->next->value)
		{
			flag = 1;
			break ;
		}
		kek = kek->next;
	}
	if (flag == 0)
		return (1);
	return(0);
}
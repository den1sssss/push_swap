/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:23:44 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/13 16:46:36 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	printstack(t_stack *stack, int flag)
{
	t_node	*kek;

	kek = stack->head;
	if (flag == 1)
		printf("\nA: ");
	if (flag == 2)
		printf("\nB: ");
	while (kek)
	{
		printf("%d ", kek->value);
		kek = kek->next;
	}
	printf("\n");
}

void	isalreadysorted(t_stack *a)
{
	t_node	*kek;
	int		flag;

	flag = 0;
	if (!a || !a->head)
		ft_error();
	if (a->size == 1)
		ft_error();
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
		// ft_error();
		exit(0);
}

int	minimum(t_stack *stack)
{
	t_node	*temp;
	int		min;

	min = MAX_INT;
	temp = stack->head;
	while (temp->next)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	maximum(t_stack *stack)
{
	t_node	*temp;
	int		max;

	max = MIN_INT;
	temp = stack->head;
	while (temp->next)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

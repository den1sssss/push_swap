/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:24:52 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/13 14:33:07 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (!stack || !stack->head || !stack->head->next)
	{
		write(2, "swap error\n", 11);
		exit(0);
	}
	a = stack->head->next;
	b = stack->head->next->next;
	stack->head->next = b;
	a->next = stack->head;
	stack->head = a;
}

void	push(t_stack *src, t_stack *dest)
{
	t_node	*a;
	t_node	*b;

	if (!src || ! dest || !src->head)
	{
		write(2, "push error!\n", 12);
		return ;
	}
	a = dest->head;
	b = src->head->next;
	dest->head = src->head;
	dest->head->next = a;
	src->head = b;
}

void	rotate(t_stack *stack)
{
	t_node	*a;
	t_node	*elem;

	if (!stack || !stack->head || !stack->head->next)
	{
		write(2, "rotate error!\n", 14);
		return ;
	}
	a = stack->head->next;
	elem = lastelem(stack);
	stack->head->next = NULL;
	elem->next = stack->head;
	stack->head = a;
}

void	reverserotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*elem;
	int		i;

	i = 1;
	if (!stack || !stack->head || !stack->head->next || !stack->size)
	{
		write(2, "revrotate error!\n", 17);
		return ;
	}
	elem = stack->head;
	while (i < stack->size - 1)
	{
		elem = elem->next;
		i++;
	}
	temp = elem->next;
	elem->next = NULL;
	temp->next = stack->head;
	stack->head = temp;
}

void	sa_sb(t_stack *stack, int whichone)
{
	swap(stack);
	if (whichone == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

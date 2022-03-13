/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globalsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:32:21 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/13 14:32:14 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble(t_parse *parse, int *a, int *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse->size)
	{
		j = 0;
		while (j < parse->size - i -1)
		{
			if (a[j] > a[j + 1])
			{
				swapelem(&a[j], &a[j + 1]);
				swapelem(&b[j], &b[j + 1]);
			}
			j++;
		}
		i++;
	}
}

int	sort_steps(t_stack *stack_b)
{
	t_node	*tmp;
	int		med;
	int		count;

	med = stack_b->size / 2;
	tmp = stack_b->head;
	count = 0;
	while (tmp->value != maximum(stack_b))
	{
		tmp = tmp->next;
		count++;
	}
	if (count < med)
		return (0);
	return (1);
}

void	ft_stack_b(t_stack *stack_b, t_stack *stack_a)
{
	while (stack_b->head->next)
	{
		if (!(stack_b))
			break ;
		if ((stack_b)->head->value != maximum(stack_b) && !sort_steps(stack_b))
			ra_rb(stack_b, 2);
		else if ((stack_b)->head->value != maximum(stack_b) && \
		sort_steps(stack_b))
			rra_rrb(stack_b, 2);
		else if ((stack_b)->head->value == maximum(stack_b))
			pa_pb(stack_a, stack_b, 1);
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int action)
{
	int	count;

	count = 0;
	while (stack_a->head)
	{
		if (count > 1 && stack_a->head->value <= count)
		{
			pa_pb(stack_a, stack_b, 2);
			ra_rb(stack_b, 2);
			count++;
		}
		else if ((stack_a)->head->value <= (count + action))
		{
			pa_pb(stack_a, stack_b, 2);
			count++;
		}
		else if ((stack_a)->head->value >= count)
			ra_rb(stack_a, 1);
	}
	ft_stack_b(stack_b, stack_a);
}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 100)
		ft_sort(stack_a, stack_b, 15);
	else
		ft_sort(stack_a, stack_b, 30);
}

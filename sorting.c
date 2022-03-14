/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:50:47 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/14 17:48:08 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_threeplus(t_stack *stack)
{
	if (stack->head->value < stack->head->next->value && \
	stack->head->next->value > stack->head->next->next->value && \
	stack->head->value > stack->head->next->next->value)
		rra_rrb(stack, 1);
	else if (stack->head->value > stack->head->next->value && \
	stack->head->next->value < stack->head->next->next->value && \
	stack->head->value > stack->head->next->next->value)
		ra_rb(stack, 1);
	else if (stack->head->value < stack->head->next->value && \
	stack->head->next->value > stack->head->next->next->value && \
	stack->head->value < stack->head->next->next->value)
	{
		rra_rrb(stack, 1);
		sa_sb(stack, 1);
	}
}

void	sort_three(t_stack *stack)
{
	while (!(stack->head->value < stack->head->next->value && \
	stack->head->next->value < stack->head->next->next->value && \
	stack->head->value < stack->head->next->next->value))
	{
		if (stack->head->value > stack->head->next->value && \
		stack->head->next->value < stack->head->next->next->value && \
		stack->head->value < stack->head->next->next->value)
			sa_sb(stack, 1);
		else if (stack->head->value > stack->head->next->value && \
		stack->head->next->value > stack->head->next->next->value && \
		stack->head->value > stack->head->next->next->value)
		{
			ra_rb(stack, 1);
			sa_sb(stack, 1);
		}
		else
			sort_threeplus(stack);
	}
}

void	push_min(t_stack *a, t_stack *b, int argc)
{
	int		min;
	t_stack	*temp;

	min = minimum(a);
	temp = a;
	if (temp->head->next->value == min)
		sa_sb(a, 1);
	else if (temp->head->next->next->value == min)
	{
		ra_rb(a, 1);
		ra_rb(a, 1);
	}
	else if (temp->head->next->next->next->value == min && argc == 6)
	{
		rra_rrb(a, 1);
		rra_rrb(a, 1);
	}
	else if ((temp->head->next->next->next->value == min && argc == 5) \
	|| (temp->head->value != min && argc == 6))
	{
		rra_rrb(a, 1);
	}
	pa_pb(a, b, 2);
}

void	sort_five(t_stack *a, t_stack *b, int argc)
{
	int	i;

	i = argc;
	while (argc != 4)
		push_min(a, b, argc--);
	sort_three(a);
	pa_pb(a, b, 1);
	if (i == 6)
		pa_pb(a, b, 1);
}

void	sorting(t_stack *a, t_stack *b, int argc)
{
	if (argc == 3)
		ra_rb(a, 1);
	else if (argc == 4)
		sort_three(a);
	else if (argc == 5 || argc == 6)
		sort_five(a, b, argc);
	else if (argc > 6)
		big_sort(a, b);
	issorted(a);
	if (!isis(a) && (argc == 5 || argc == 6))
		sort_five(a, b, argc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:22:33 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/13 14:31:06 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb(t_stack *a, t_stack *b, int whichone)
{
	if (whichone == 1)
	{
		push(b, a);
		a->size++;
		b->size--;
		write (1, "pa\n", 3);
	}
	else
	{
		push(a, b);
		a->size--;
		b->size++;
		write (1, "pb\n", 3);
	}
}

void	ra_rb(t_stack *stack, int whichone)
{
	rotate(stack);
	if (whichone == 1)
		write (1, "ra\n", 3);
	else
		write (1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}

void	rra_rrb(t_stack *stack, int whichone)
{
	reverserotate(stack);
	if (whichone == 1)
		write (1, "rra\n", 4);
	else
		write (1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverserotate(a);
	reverserotate(b);
	write (1, "rrr\n", 4);
}

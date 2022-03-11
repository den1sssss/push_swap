#include "push_swap.h"
// void right_ind(t_stack *a)
// {
// 	//!!!!
// 	int len;
// 	t_stack *temp;
// 	int j;

// 	temp = a;
// 	len = a->size;
// 	while(temp->next)
// 	{
// 		j=0;
// 		while(j<len)
// 		{
// 			if(temp->head->value) //?)
// 			{
// 				(*temp).head->score=j;
// 				break;
// 			}
// 			j++;
// 		}
// 		temp=temp->head->next;
// 	}

// }
// // int max_ind(t_stack *stack)
// // {
// // 	// int max;
// // 	// t_stack *temp;

// // 	// max = 0;
// // 	// temp=stack;
// // 	// right_ind(stack);
// // 	// while(temp)
// // 	// {
// // 	// 	if(max < temp->head->value)
// // 	// 		max=temp->head->value;
// // 	// 	temp->head->next;
// // 	// }
// // 	// return (max);
// // 	t_node *temp;
// // 	int max;

// // 	max = 0;
// // 	temp = stack->head;

// // 	while(temp->next)
// // 	{
// // 		if(temp->)
// // 	}
// // 	return(j)

// // }
// static int placeofmax(t_stack *stack, int max)
// {
// 	int j;
// 	t_stack *temp;
	
// 	j = 0;
// 	temp = stack;
// 	while(temp->head->next)
// 	{
// 		if(temp->head->value == max)
// 			break;
// 		temp=temp->head->next;
// 		j++;
// 	}
// 	return (j);
// }
// static void sort_b(t_stack *a,t_stack *b)
// {
// 	int arg;
// 	int j;
// 	int max;
// 	while(b->next)
// 	{
// 		arg = b->size / 2;
// 		// max=max_ind(b);
// 		j = placeofmax(b,max);
// 		if(b->head->value == max)
// 			pa_pb(a,b,2);
// 		else if(b->head->value != max && j > arg)
// 			rra_rrb(b,2);
// 		else if(b->head->value != max && j < arg)
// 			ra_rb(b,2);
// 	}
// }
// void globalsort(t_stack *a,t_stack *b)
// {
// 	int j;

// 	j = 0;
// 	// right_ind(a);
// 	{
// 		while(a->next)
// 		{
// 			if(j > 0 && a->head->value <= j)
// 			{
// 				pa_pb(a,b,2);
// 				ra_rb(b,1);
// 				j++;
// 			}
// 			else if(a->head->value >= j)
// 				ra_rb(a,1);
// 			else if(a->head->value <= (j+23))
// 			{
// 				pa_pb(a,b,2);
// 				j++;
// 			}
// 		}
// 		sort_b(a,b);
// 	}
// }




// ----------------------------//


int	sort_steps(t_stack *stack_b)
{
	t_node	*tmp;
	int			med;
	int			count;

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

// int	max_value(t_stack *stack_b)
// {
// 	int			max_value;
// 	t_stack	*tmp;

// 	tmp = 	stack_b;
// 	max_value = tmp->head->value;
// 	while (tmp)
// 	{
// 		if (max_value < tmp->head->value)
// 			max_value = tmp->head->value;
// 		tmp = tmp->head->next;
// 	}
// 	return (max_value);
// }

// int	min_value(t_stack *stack_b)
// {
// 	int			min_value;
// 	t_stack	*tmp;

// 	tmp = stack_b;
// 	min_value = tmp->head->value;
// 	while (tmp)
// 	{
// 		if (min_value > tmp->head->value)
// 			min_value = tmp->head->value;
// 		tmp = tmp->head->next;
// 	}
// 	return (min_value);
// }

static void	ft_stack_b(t_stack *stack_b, t_stack *stack_a)
{
	// printf("\nhere we go again\n");
	while (stack_b->head->next)
	{
		if (!(stack_b))
			break ;
		if ((stack_b)->head->value != maximum(stack_b) && !sort_steps(stack_b))
			ra_rb(stack_b,2);
		else if ((stack_b)->head->value != maximum(stack_b) && sort_steps(stack_b))
			rra_rrb(stack_b,2);
		else if ((stack_b)->head->value == maximum(stack_b))
			pa_pb(stack_a,stack_b,1);
	}
	// printf("END");
}

static void	ft_sort(t_stack *stack_a, t_stack *stack_b, int action)
{
	int	count;

	count = 0;
	while (stack_a->head)
	{
		if (count > 1 && stack_a->head->value <= count)
		{
			// printf("[kek]");
			// pb(stack_a, stack_b);
			pa_pb(stack_a,stack_b,2);
			ra_rb(stack_b,2);
			count++;
		}
		else if ((stack_a)->head->value <= (count + action))
		{
			// printf("[lel]");
			pa_pb(stack_a,stack_b,2);
			// pb(stack_a, stack_b);
			count++;
		}
		else if ((stack_a)->head->value >= count)
			// ra(stack_a);
		{
			// printf("[puk]");
			ra_rb(stack_a,1);
		}
	}
	// printf("[else]");
	ft_stack_b(stack_b, stack_a);
}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 100)
		ft_sort(stack_a, stack_b, 15);
	else
		ft_sort(stack_a, stack_b, 30);
	printstack(stack_a,1);
}
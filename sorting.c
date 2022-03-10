#include "push_swap.h"
int isalreadysorted(t_stack *a)
{
	t_node *kek;
	int flag;

	flag = 0;
	if(!a || !a->head)
		return (0);
	if(a->size == 1)
		return (1);
	kek=a->head;
	while(kek->next)
	{
		if(kek->value > kek->next->value)
			{
				flag = 1;
				break;
			}
		kek=kek->next;
	}
	return(flag);
}
int minimum(t_stack *stack)
{
	int min;

	min=MAX_INT;
	while(stack)
	{
		if(min>stack->head->value)
			min= stack->head->value;
		stack=stack->head->next;
	}
	return (min);
}
void sort_three(t_stack *stack)
{
	while(!(stack->head->value < stack->head->next->value && \
	stack->head->next->value < stack->head->next->next->value && \
	stack->head->value < stack->head->next->next->value))
	{
		if(stack->head->value > stack->head->next->value && \
		stack->head->next->value < stack->head->next->next->value && \
		stack->head->value <stack->head->next->next->value)
			sa_sb(stack,1);
		else if(stack->head->value > stack->head->next->value && \
		stack->head->next->value > stack->head->next->next->value && \
		stack->head->value > stack->head->next->next->value)
		{
			ra_rb(stack,1);
			sa_sb(stack,1);
		}
		else if(stack->head->value < stack->head->next->value && \
		stack->head->next->value > stack->head->next->next->value && \
		stack->head->value > stack->head->next->next->value)
			rra_rrb(stack,1);
		else if(stack->head->value > stack->head->next->value && \
		stack->head->next->value < stack->head->next->next->value && \
		stack->head->value > stack->head->next->next->value)
			ra_rb(stack,1);
		else if(stack->head->value < stack->head->next->value && \
		stack->head->next->value > stack->head->next->next->value && \
		stack->head->value < stack->head->next->next->value)
		{
			rra_rrb(stack,1);
			sa_sb(stack,1);
		}

	}  
}

void push_min(t_stack *a,t_stack *b,int argc)
{
	int min;

	min = minimum(a);
	printf("[min = %d]\n",min);
	if(a->head->next->value == min)
		sa_sb(a,1);
	else if(a->head->next->next->value == min)
	{
		ra_rb(a,1);
		ra_rb(a,1);
	}
	else if(a->head->next->next->next->value == min && argc == 6)
	{
		rra_rrb(a,1);
		rra_rrb(a,1);
	}
	else if((a->head->next->next->next->value == min && argc == 5) || (a->head->value != min && argc == 6))
		rra_rrb(a,1);
	pa_pb(a,b,2);

}
void sort_five(t_stack *a,t_stack *b,int argc)
{
	int temp;

	temp=argc;
	while(argc != 4)
		push_min(a,b,argc--);
	sort_three(a);
	pa_pb(a,1);
	if(temp == 6)
		pa_pb(a,1);
}

void sorting(t_stack *a,t_stack *b,int argc,char **argv)
{
	if(isalreadysorted(a)==1)
	{
		printf("\nStack already sorted\n");
		// exit(0);
	}
	if(argc == 3)
		rotate(a);
	if(argc == 4)
		sort_three(a);
	if (argc == 5 || argc == 6)
		sort_five(a,b,argc);
}
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
	t_node *temp;
	int min;

	min=MAX_INT;
	// temp = stack->head;
	// while(temp && temp->)
	// {
	// 	if(min > temp->head->value)
	// 		min= temp->head->value;
	// 	temp=temp->head->next;
	// 	// temp = (*temp).head->next;
	// }
	// printf("[=)]");
	// t_node *a;

	temp=stack->head;
	while(temp->next)
	{
		if(min > temp->value)
			min = temp->value;
		temp=temp->next;
	}
	return (min);
}
int maximum(t_stack *stack)
{
	t_node *temp;
	int max;

	max=MIN_INT;
	// temp = stack->head;
	// while(temp && temp->)
	// {
	// 	if(min > temp->head->value)
	// 		min= temp->head->value;
	// 	temp=temp->head->next;
	// 	// temp = (*temp).head->next;
	// }
	// printf("[=)]");
	// t_node *a;

	temp=stack->head;
	while(temp->next)
	{
		if(max < temp->value)
			max = temp->value;
		temp=temp->next;
	}
	return (max);
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
	t_stack *temp;

	min = minimum(a);
	temp = a;
	// printf("\n[min = %d]\n",min);
	if(temp->head->next->value == min)
		sa_sb(a,1);
	else if(temp->head->next->next->value == min)
	{
		// printf("1\n");
		ra_rb(a,1);
		ra_rb(a,1);
	}
	else if(temp->head->next->next->next->value == min && argc == 6)
	{
		// printf("2\n");
		rra_rrb(a,1);
		rra_rrb(a,1);

	}
	else if((temp->head->next->next->next->value == min && argc == 5) \
	|| (temp->head->value != min && argc == 6))
	{
		// printf("3\n");
		rra_rrb(a,1);
	}
	// printf("4\n");
	pa_pb(a,b,2);
	printf("---\n");

}
void sort_five(t_stack *a,t_stack *b,int argc)
{
	int i;

	i=argc;
	while(argc != 4)
	{
		// printf("%d argc\n",argc);
		push_min(a,b,argc--);
		// printf("\npls1\n");
		// printf("minimum %d",minimum(a));
		// printf("\npls1\n");
		// printstack(a,1);
	}
	// printf("pls");
	printstack(a,1);
	printstack(b,2);

	sort_three(a);
	pa_pb(a,b,1);
	if(i == 6)
		pa_pb(a,b,1);
	// printstack(a,1);
}

void sorting(t_stack *a,t_stack *b,int argc,char **argv)
{
	if(isalreadysorted(a)==1)
	{
		printf("\nStack already sorted\n\n");
		// exit(0);
	}
	printstack(a,1);
	if(argc == 3)
		ra_rb(a,1);
	else if(argc == 4)
		sort_three(a);
	else if (argc == 5 || argc == 6)
		sort_five(a,b,argc);
	printstack(a,1);
	if(argc > 6)
		// globalsort(a,b);
		big_sort(a,b);
		
}
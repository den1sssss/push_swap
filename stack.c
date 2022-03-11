#include "push_swap.h"
void printstack(t_stack *stack, int flag)
{
	t_node *kek;

	kek= stack->head;
	if(flag == 1)
		printf("\nA: ");
	if(flag == 2)
		printf("\nB: ");
	while(kek)
	{
		printf("%d ", kek->value);
		kek=kek->next;
	}
	printf("\n");
	// printf("\n[next: %d | ",stack->next);
	// printf("size: %d]\n",stack->size);
}
t_node *node_create(int value)
{
	t_node *new;
	new=(t_node*)malloc(sizeof(t_node));
	if(!new)
		return(0);
	new->value=value;
	new->flag=0;
	new->next=NULL;
	return(new);
}

t_node *lastelem(t_stack *stack)
{
	t_node *a;

	if(!stack || !stack->head)
		return(NULL);
	a=stack->head;
	while(a->next)
		a=a->next;
	return(a);
}

void addelem(t_stack *stack,t_node *elem)
{
	t_node *a;
	if(!stack || !elem)
		{
			printf("addelem error!\n");
			exit(0);
		}
	a=lastelem(stack);
	if(!a)
	{
		stack->head=elem;
		return;
	}
	a->next=elem;
}

t_stack *initialize(int size)
{
	t_stack *stack;

	stack= (t_stack *)malloc(sizeof(t_stack));
	if(!stack)
		{
			printf("initialize stack error!\n");
			exit(0);
		}
	stack->head=NULL;
	stack->size=size;
	return (stack);
}
t_stack *create_stack(int size, int *arr)
{
	t_node *temp;
	t_stack *stack;
	int i;

	i=0;
	stack=initialize(size);
	temp=stack->head;
	while(i < stack->size)
		addelem(stack,node_create(arr[i++]));
	stack->next=1;

	return(stack);
}


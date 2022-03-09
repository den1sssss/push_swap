#include "push_swap.h"
void swap(t_stack *stack)
{
	t_node *a;
	t_node *b;

	if(!stack || !stack->head || !stack->head->next)
	{
		printf("swap error\n");
		exit(0);
	}
	a=stack->head->next;
	b=stack->head->next->next;
	stack->head->next=b;
	a->next=stack->head;
	stack->head=a;
}

void push(t_stack *src,t_stack *dest)
{
	t_node *a;
	t_node *b;

	if(!src || ! dest || !src->head)
	{
		printf("push error!\n");
		return;
	}
	a=dest->head;
	b=src->head->next;
	dest->head=src->head;
	dest->head->next=a;
	src->head=b;
}

void rotate(t_stack *stack)
{
	t_node *a;
	t_node *elem;

	if(!stack || !stack->head || !stack->head->next)
	{
		printf("rotate error!\n");
		return;
	}
	a=stack->head->next;
	elem=lastelem(stack);
	stack->head->next=NULL;
	elem->next=stack->head;
	stack->head=a;
}

void reverserotate(t_stack *stack)
{
	t_node *temp;
	t_node *elem;
	int i;

	i = 1;
	if(!stack || !stack->head || !stack->head->next || !stack->size)	
	{
		printf("revrotate error!\n");
		return;
	}
	elem=stack->head;
	while(i<stack->size-1)
	{
		elem=elem->next;
		i++;
	}
	temp=elem->next;
	elem->next=NULL;
	temp->next=stack->head;
	stack->head=temp;
}

void sa_sb(t_stack *stack,int whichone)
{
	swap(stack);
	if(whichone == 1)
		printf("sa\n");
	else
		printf("sb\n");
}
void ss(t_stack *a,t_stack *b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
void pa_pb(t_stack *a,t_stack *b,int whichone)
{
	if(whichone == 1)
	{
		push(b,a);
		a->size++;
		b->size--;
		printf("pa\n");
	}
	else
	{
		push(a,b);
		a->size--;
		b->size++;
		printf("pb\n");
	}
}
void ra_rb(t_stack *stack,int whichone)
{
	rotate(stack);
	if(whichone == 1)
		printf("ra\n");
	else
		printf("rb\n");
}
void rr(t_stack *a,t_stack *b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
void rra_rrb(t_stack *stack,int whichone)
{
	reverserotate(stack);
	if(whichone == 1)
		printf("rra\n");
	else
		printf("rrb\n");
}
void rrr(t_stack *a,t_stack *b)
{
	reverserotate(a);
	reverserotate(b);
	printf("rrr\n");
}
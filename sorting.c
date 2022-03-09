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

void sorting(t_stack *a,t_stack *b)
{
	if(isalreadysorted(a)==1)
	{
		printf("Stack already sorted");
		// exit(0);
	}
}
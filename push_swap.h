#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
typedef struct		s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct		s_data
{
	int				a[10000];
	int				count_element;
}					t_data;

typedef struct s_list
{
	int				data;
	int				step;
	int				rotate;
	struct s_list	*next;
}   				t_list;

typedef struct s_lists
{
	int				count_a;
	int				count_b;
	int				min;
	int				max;
	int				avg;
	t_list			*a;
	t_list			*b;
}   				t_lists;




#endif

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
// typedef struct		s_steps
// {
// 	int				count_a;
// 	int				count_b;
// 	int				dest_a;
// 	int				dest_b;
// }					t_steps;

// typedef struct		s_data
// {
// 	int				a[10000];
// 	int				count_element;
// }					t_data;

// typedef struct s_list
// {
// 	int				data;
// 	int				step;
// 	int				rotate;
// 	struct s_list	*next;
// }   				t_list;

// typedef struct s_lists
// {
// 	int				count_a;
// 	int				count_b;
// 	int				min;
// 	int				max;
// 	int				avg;
// 	t_list			*a;
// 	t_list			*b;
// }   				t_lists;

///////////

// typedef struct s_node
// {
// 	// int				num;
// 	int				index;
// 	int				flag;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// }				t_node;

// typedef struct s_all
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	int		min_a;
// 	int		med;
// 	int		len_a;
// 	int		len_b;
// }				t_all;

typedef struct s_node
{
	struct s_node	*next;
	
	int		value;
	
	long		score;
}				t_node;

typedef struct s_arr
{
	struct s_node	*head;
	int				size;
		
}				t_arr;

typedef struct	s_parse
{
	char 	**big_str;
	int		*big_array;
	int		parse_size;
	
	int		*ind_array;
	int		*sorted_ind_array;
	
}				t_parse;

#endif

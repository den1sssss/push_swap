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
	
	int			value;
	long		score;
	int			flag;
}				t_node;

typedef struct s_stack
{
	struct s_node	*head;
	int				size;
	int				max;
	int				mid;
	int				next;
	int				flag;
		
}				t_stack;

typedef struct	s_parse
{
	char 	**big_str;
	int		*array;
	int		size;
	int		*ind_array;
	int		*sorted_ind_array;
	
}				t_parse;




# define MAX_INT 2147483647
# define MIN_INT -2147483648


void printstack(t_stack *stack, int flag);
t_node *node_create(int value);
t_node *lastelem(t_stack *stack);
void addelem(t_stack *stack,t_node *elem);
t_stack *initialize(int size);
t_stack *create_stack(int size, int *arr);
void sorting(t_stack *a,t_stack *b,int argc,char **argv);
int isalreadysorted(t_stack *a);
void sort_three(t_stack *stack);
void sort_five(t_stack *a,t_stack *b,int argc);
int minimum(t_stack *stack);


void swap(t_stack *stack);
void push(t_stack *src,t_stack *dest);
void rotate(t_stack *stack);
void reverserotate(t_stack *stack);
void sa_sb(t_stack *stack,int whichone);
void ss(t_stack *a,t_stack *b);
void pa_pb(t_stack *a,t_stack *b,int whichone);
void ra_rb(t_stack *stack,int whichone);
void rr(t_stack *a,t_stack *b);
void rra_rrb(t_stack *stack,int whichone);
void rrr(t_stack *a,t_stack *b);


// void globalsort(t_stack *a,t_stack *b);
// static void sort_b(t_stack *a,t_stack *b);
// static int placeofmax(t_stack *stack, int max);
// int max_ind(t_stack *stack);
// void right_ind(t_stack *a);


int maximum(t_stack *stack);
void	big_sort(t_stack *stack_a, t_stack *stack_b);
static void	ft_sort(t_stack *stack_a, t_stack *stack_b, int action);
static void	ft_stack_b(t_stack *stack_b, t_stack *stack_a);
int	min_value(t_stack *stack_b);
int	max_value(t_stack *stack_b);
int	sort_steps(t_stack *stack_b);


#endif

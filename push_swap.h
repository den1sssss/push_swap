/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:04:55 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/14 13:51:15 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	int				value;
	long			score;
	int				flag;
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

typedef struct s_parse
{
	char	**big_str;
	int		*array;
	int		size;
	int		*ind_array;
	int		*sorted_ind_array;
}				t_parse;

# define MAX_INT 2147483647
# define MIN_INT -2147483648

void	printstack(t_stack *stack, int flag);
t_node	*node_create(int value);
t_node	*lastelem(t_stack *stack);
void	addelem(t_stack *stack, t_node *elem);
t_stack	*initialize(int size);
t_stack	*create_stack(int size, int *arr);
void	sorting(t_stack *a, t_stack *b, int argc);
void	isalreadysorted(t_stack *a);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *a, t_stack *b, int argc);
int		minimum(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverserotate(t_stack *stack);
void	sa_sb(t_stack *stack, int whichone);
void	ss(t_stack *a, t_stack *b);
void	pa_pb(t_stack *a, t_stack *b, int whichone);
void	ra_rb(t_stack *stack, int whichone);
void	rr(t_stack *a, t_stack *b);
void	rra_rrb(t_stack *stack, int whichone);
void	rrr(t_stack *a, t_stack *b);
int		maximum(t_stack *stack);
void	big_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b, int action);
void	ft_stack_b(t_stack *stack_b, t_stack *stack_a);
int		min_value(t_stack *stack_b);
int		max_value(t_stack *stack_b);
int		sort_steps(t_stack *stack_b);
void	ft_error(void);
void	output(char **str);
void	writearray(t_parse *parse);
void	printmassiv(int *A);
int		ft_otoi(char *str);
int		prevalid(char *str);
void	validation(t_parse *parse);
int		words(char **str);
void	duplicates(t_parse *parse);
int		*create_ind_array(int len);
void	bubble(t_parse *parse, int *a, int *b);
void	swapelem(int *a, int *b);
void	atoi_checker(char *str, int sign);


void	issorted(t_stack *a);
int		isis(t_stack *a);

#endif

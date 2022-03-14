/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:34:11 by dshirely          #+#    #+#             */
/*   Updated: 2022/03/14 15:11:47 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapelem(int *a, int *b)
{
	int	kek;

	kek = *a;
	*a = *b;
	*b = kek;
}

void	presort(t_parse *parse, int flag)
{
	int	*a;
	int	*b;

	if (flag == 0)
		a = parse->array;
	else
		a = parse->ind_array;
	b = create_ind_array(parse->size);
	bubble(parse, a, b);
	if (flag == 0)
		parse->ind_array = b;
	if (flag == 1)
		parse->sorted_ind_array = b;
}

void	create_array(t_parse *parse)
{
	int	i;

	i = 0;
	parse->array = (int *)malloc(sizeof(int) * parse->size);
	if (!parse->big_str || !parse->array)
		ft_error();
	while (i < parse->size)
	{
		parse->array[i] = ft_otoi(parse->big_str[i]);
		i++;
	}
	presort(parse, 0);
	duplicates(parse);
	presort(parse, 1);
}

void	parser(int argc, char **argv, t_parse *parse)
{
	char	*str;
	int		i;

	i = 1;
	str = ft_strdup(" ");
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, ft_strdup(" "));
		i++;
	}
	parse->big_str = ft_split(str, ' ');
	parse->size = words(parse->big_str);
	free(str);
	create_array(parse);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_parse	parse;

	if (argc > 2)
	{
		parser(argc, argv, &parse);
		a = create_stack(parse.size, parse.sorted_ind_array);
		// printstack(a,1);
		isalreadysorted(a);
		b = initialize(0);
		sorting(a, b, argc);
		// printstack(a,1);
		// printstack(b,2);

	}
	// else
		// ft_error();
		// write(1,"\n",1);
		exit(0);
	return (0);
}

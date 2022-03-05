#include "push_swap.h"
void ft_error()
{
	write(1,"error",5);
}
void output(char **str)
{
	while(*str)
		printf("%s ",*str++);
}
int	ft_otoi(const char *str)
{
	long				znak;
	unsigned long long	sum;

	znak = 1;
	sum = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		str++;
		znak *= -1;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	if (sum > 2147483647 && znak + 1)
		return (-1);
	if (sum > 2147483648)
		return (0);
	return ((int)sum * znak);
}
void totalcheck()
{

}
int prevalid(char *str)
{
	int i;

	i = 0;

	while(*str)
	{
		if(ft_otoi(str++)==-1)
		{
			return (0);
			break;
		}
	}
	return (1);
}

int validation(t_parse *parse)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 1;
	while(parse->big_str[i])
	{
		if(prevalid(parse->big_str[i])==0)
		{
			// printf("aboba");
			flag = 0;
			break;
		}
		i++;
	}
	if (flag == 0)
		return (0);
	else
		return (1);
}

int words(char **str)
{
	int i;

	i = 0;
	if(!str)
		return 0;
	while(str[i])
		i++;
	return (i);
}
void parser(int argc, char **argv, t_parse *parse)
{
	char *str;
	int i;

	i = 1;
	str = ft_strdup(" ");
	while(i < argc)
	{
		str=ft_strjoin(str,argv[i]);
		str=ft_strjoin(str,ft_strdup(" "));
		i++;
	}
	parse->big_str=ft_split(str,' ');
	parse->parse_size=words(parse->big_str);
	output(parse->big_str);
	if(validation(parse)==0)
		ft_error();
}


int main(int argc, char **argv)
{
	t_arr *list;
	t_node *temp;
	t_parse	parse;
	if(argc > 2)
		{
			parser(argc,argv,&parse);
			// sorting();
			// free_stack();
		}
	// else
	// {
	// 	// ft_error();
	// 	exit(0);
	// }
	return (0);
}
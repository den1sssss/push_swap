#include "push_swap.h"
void ft_error()
{
	write(1,"error",5);
	exit(0);
}
void output(char **str)
{
	while(*str)
		printf("%s ",*str++);
	printf("\n");
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
int prevalid(char *str)
{
	int i;

	i = 0;

	while(*str)
	{
		if(ft_otoi(str++)==-1)
		{
			ft_error();
			// return (0);
			// break;
		}
	}
	return (1);
}

void validation(t_parse *parse)
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
		ft_error();
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
void create_array(t_parse *parse)
{
	int i;

	i = 0;
	parse->array =(int *)malloc(sizeof(int)*parse->size);
	if (!parse->big_str || !parse->array)
		ft_error();
	while(i<parse->size)
	{
		parse->array[i]=ft_otoi(parse->big_str[i]);
		i++;
	}
}

void writearray(t_parse *parse)
{
	int i;

	i=0;
	while(i<parse->size)
	{
		ft_putnbr_fd(parse->array[i],0);
		write(0," ",1);
		i++;
	}
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
	parse->size=words(parse->big_str);
	printf("\nwords:  %d\n",words(parse->big_str));
	printf("\noutput (str) : ");
	output(parse->big_str);
	printf("\nwritearray:\n ");
	validation(parse);
	create_array(parse);
	writearray(parse);
}


int main(int argc, char **argv)
{
	t_stack *list;
	t_node *temp;
	t_parse	parse;
	if(argc > 2)
		{
			parser(argc,argv,&parse);
			// sorting();
			// free_stack();
		}
	else
	{
		ft_error();
	}
	return (0);
}
#include "push_swap.h"
int ft_atoi(char *str)
{
	int i;

	i = 0;
	if(ft_isdigit())
}
void prevalid(char *str)
{
	int i;

	i = 0;
	while()
	{
		
	}
}
void validation(char **str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		prevalid(&str[i]);
		i++;
	}
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
void output(char **str)
{
	while(*str)
		printf("%s ",*str++);
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
	validation(parse->big_str);

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
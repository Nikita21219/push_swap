/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:24:39 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 21:36:54 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	len_el(t_data *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_data	*init(int val, char c)
{
	t_data	*result;

	result = (t_data *)malloc(sizeof(t_data));
	if (!result)
		return (NULL);
	result->next = NULL;
	result->prev = NULL;
	result->val = val;
	result->c = c;
	return (result);
}

char	*get_next_arg(char *str)
{
	while (*str)
	{
		if (*str == ' ')
		{
			while (*str == ' ')
				str++;
			if (*str)
				return (str);
		}
		str++;
	}
	return (NULL);
}

void	init_a(char **argv, t_data **a)
{
	int		i;
	char	*arg;

	i = 0;
	while (argv[i])
	{
		arg = argv[i];
		while (arg)
		{
			ft_el_add_back(a, init(ft_atoi(arg), 'a'));
			while (*arg == ' ')
				arg++;
			arg = get_next_arg(arg);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*a;
	t_data	*b;
	t_data	*operations;
	char	*buf;

	if (argc == 1)
		return (0);
	buf = error_operations();
	if (is_error_arg(++argv) || !buf)
		return (print_error());
	a = NULL;
	b = NULL;
	operations = NULL;
	init_a(argv, &a);
	if (len_el(a) < 2 || finish_sort(a))
		return (mem_free(a));
	if (duplicates_in_stack(a))
		return (free_stack(a));
	main_logic(&a, &b, &operations, buf);
	if (finish_sort(a) && !(b))
		return (print_result(1));
	return (print_result(0));
}

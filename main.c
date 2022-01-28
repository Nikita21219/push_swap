/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:37:57 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 10:39:52 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	init_stack_a(char **argv, t_data **stack_a)
{
	int		i;
	char	*arg;

	i = 0;
	while (argv[i])
	{
		arg = argv[i];
		while (arg)
		{
			ft_el_add_back(stack_a, init(ft_atoi(arg), 'a'));
			while (*arg == ' ')
				arg++;
			arg = get_next_arg(arg);
		}
		i++;
	}
}

int	main(int argc, char **argv)
/* 0:sa 1:sb 2:ss 3:pa 4:pb 5:ra 6:rb 7:rr 8:rra 9:rrb 10:rrr */
{
	t_data	*stack_a;
	t_data	*stack_b;
	t_data	*operations;

	if (argc == 1)
		return (0);
	if (is_error_arg(++argv))
		return (print_error());
	stack_a = NULL;
	stack_b = NULL;
	operations = NULL;
	init_stack_a(argv, &stack_a);
	if (len_el(stack_a) < 2 || finish_sort(stack_a))
		return (mem_free(stack_a));
	if (duplicates_in_stack(stack_a))
		return (free_stack(stack_a));
	if (len_el(stack_a) == 3)
		sort_by_three(&stack_a, &operations);
	else if (len_el(stack_a) == 2)
		sort_by_two(&stack_a, &operations);
	else
		main_sort(&stack_a, &stack_b, &operations);
	print_operations(&operations);
	free_stacks(&stack_a, &stack_b, &operations);
	return (0);
}

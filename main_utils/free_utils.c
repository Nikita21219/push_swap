/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:56:56 by a1                #+#    #+#             */
/*   Updated: 2022/01/26 12:33:23 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_stack(t_data *stack)
{
	t_data	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return (print_error());
}

int	mem_free(t_data *stack)
{
	t_data	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return (0);
}

void	free_stacks(t_data **stack_a, t_data **stack_b, t_data **operations)
{
	t_data	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
	while (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
	}
	while (*operations)
	{
		tmp = *operations;
		*operations = (*operations)->next;
		free(tmp);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	*operations = NULL;
}

int	is_duplicate(t_data *stack, int val, int i)
{
	while (i--)
	{
		if (stack->val == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	duplicates_in_stack(t_data *stack)
{
	int		i;
	t_data	*start_stack;

	i = 0;
	start_stack = stack;
	while (stack)
	{
		if (is_duplicate(start_stack, stack->val, i))
			return (1);
		stack = stack->next;
		i++;
	}
	return (0);
}

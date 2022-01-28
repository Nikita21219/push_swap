/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:57:07 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 11:46:18 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_b(t_data **stack_a, t_data **stack_b, t_data **operations)
{
	int	mid;
	int	max;
	int	min;
	int	len_a;

	max = get_max(*stack_a);
	min = get_min(*stack_a);
	mid = get_mid(*stack_a);
	len_a = len_el(*stack_a);
	while (!is_empty(*stack_a, min, max, mid))
	{
		if ((*stack_a)->val == mid || (*stack_a)->val == min || \
		(*stack_a)->val == max)
			rotate(stack_a, operations);
		else
		{
			push(stack_a, stack_b, operations);
			if ((*stack_b)->val >= mid && len_a > 5)
				rotate(stack_b, operations);
		}
	}
	sort_by_three(stack_a, operations);
}

t_data	*get_max_el(t_data **stack)
{
	t_data	*current;
	t_data	*max;

	current = *stack;
	max = *stack;
	while (current)
	{
		if (max->val < current->val)
			max = current;
		current = current->next;
	}
	return (max);
}

int	is_sort(t_data *stack)
{
	t_data	*start;

	start = stack;
	while (stack->next && stack->val != get_min(stack))
	{
		if (stack->val > stack->next->val)
		{
			stack = stack->next;
			break ;
		}
		stack = stack->next;
	}
	if (stack->val == get_min(stack))
	{
		while (stack->next)
		{
			if (stack->val > stack->next->val)
				return (0);
			stack = stack->next;
		}
	}
	else
		return (0);
	return (1);
}

void	mini_sort(t_data **stack_a, t_data **stack_b, t_data **operations)
{
	while (len_el(*stack_a) > 3)
		push(stack_a, stack_b, operations);
	if (len_el(*stack_b) == 2)
		sort_by_two(stack_b, operations);
	sort_by_three(stack_a, operations);
	while (len_el(*stack_b) > 1)
	{
		if (get_max(*stack_a) > get_min(*stack_b))
			while ((*stack_a)->val < (*stack_b)->val)
				rotate(stack_a, operations);
		else
			while ((*stack_a)->val != get_min(*stack_a))
				rotate(stack_a, operations);
		push(stack_b, stack_a, operations);
	}
	if (get_max(*stack_a) < (*stack_b)->val)
		while ((*stack_a)->val != get_min(*stack_a))
			rotate(stack_a, operations);
	else
		while ((*stack_a)->val < (*stack_b)->val)
			rotate(stack_a, operations);
	push(stack_b, stack_a, operations);
	while ((*stack_a)->val != get_min(*stack_a))
		rotate(stack_a, operations);
}

void	main_sort(t_data **stack_a, t_data **stack_b, t_data **operations)
{
	int	min;

	min = get_min(*stack_a);
	if (len_el(*stack_a) < 6)
	{
		mini_sort(stack_a, stack_b, operations);
		return ;
	}
	fill_b(stack_a, stack_b, operations);
	while (len_el(*stack_b))
		sort_logic(stack_a, stack_b, operations);
	if (get_index_with_val(*stack_a, min) > len_el(*stack_a) / 2)
		while ((*stack_a)->val != min)
			reverse_rotate(stack_a, operations);
	else
		while ((*stack_a)->val != min)
			rotate(stack_a, operations);
}

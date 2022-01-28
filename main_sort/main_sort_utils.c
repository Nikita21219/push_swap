/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:09:14 by a1                #+#    #+#             */
/*   Updated: 2022/01/26 20:09:45 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max(t_data *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (max < stack->val)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

int	get_min(t_data *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (min > stack->val)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

int	is_empty(t_data *stack, int min, int max, int mid)
{
	while (stack)
	{
		if (stack->val != min && stack->val != max && stack->val != mid)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_by_three(t_data **stack_a, t_data **operations)
{
	int	f;
	int	s;
	int	t;

	f = (*stack_a)->val;
	s = (*stack_a)->next->val;
	t = (*stack_a)->next->next->val;
	if (f < s && s > t && t > f)
	{
		swap(stack_a, operations);
		rotate(stack_a, operations);
	}
	else if (f < s && s > t && t < f)
		reverse_rotate(stack_a, operations);
	else if (f > s && s < t && t > f)
		swap(stack_a, operations);
	else if (f > s && s < t && t < f)
		rotate(stack_a, operations);
	else if (f > s && s > t && t < f)
	{
		swap(stack_a, operations);
		reverse_rotate(stack_a, operations);
	}
}

int	do_not_push(int val, t_data **copy_a, int start_ind, int finish_ind)
{
	t_data	*current;
	int		count;
	int		tmp_start_ind_sort;

	current = *copy_a;
	tmp_start_ind_sort = start_ind;
	while (current && tmp_start_ind_sort--)
		current = current->next;
	count = finish_ind - start_ind + 1;
	while (current && count--)
	{
		if (current->val == val)
			return (1);
		current = current->next;
	}
	return (0);
}

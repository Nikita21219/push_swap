/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:44:29 by a1                #+#    #+#             */
/*   Updated: 2022/01/26 20:35:05 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index_with_val(t_data *stack, int val)
{
	int	count;

	count = 0;
	while (stack->next)
	{
		if (stack->val == val)
			return (count);
		stack = stack->next;
		count++;
	}
	return (-1);
}

t_data	*get_correct_elem(t_data **stack_a, t_data **stack_b)
{
	t_data	*cur;

	cur = *stack_a;
	if ((*stack_a)->val < (*stack_b)->val && \
	ft_last_el(*stack_a)->val > (*stack_b)->val && \
	(*stack_b)->val < ft_last_el(*stack_b)->val)
		return (cur);
	while (cur->next)
	{
		if (cur->val < (*stack_b)->val && cur->next->val > (*stack_b)->val)
			return (cur->next);
		cur = cur->next;
	}
	return (*stack_a);
}

void	move_element_to_top_stack_a(t_data **a, t_data **b, t_data **op)
{
	t_data	*correct;
	int		flag;

	flag = 1;
	correct = get_correct_elem(a, b);
	while ((*a) != correct)
	{
		if (get_index_with_val(*a, correct->val) < \
		len_el(*a) / 2 && flag)
			rotate(a, op);
		else
		{
			flag = 0;
			reverse_rotate(a, op);
		}
	}
}

t_data	*get_el_with_min_score(t_data **stack)
{
	t_data	*el_with_min_score;
	t_data	*current;

	el_with_min_score = *stack;
	current = *stack;
	while (current->next)
	{
		if (el_with_min_score->score > current->score)
			el_with_min_score = current;
		current = current->next;
	}
	return (el_with_min_score);
}

void	move_element_to_top_stack_b(t_data **stack, t_data **operations)
{
	t_data	*correct_elem;
	int		flag;

	flag = 1;
	correct_elem = get_el_with_min_score(stack)->next;
	while ((*stack)->next != correct_elem)
	{
		if (flag && get_index_with_val(*stack, correct_elem->val) \
		< len_el(*stack) / 2)
			rotate(stack, operations);
		else
		{
			flag = 0;
			reverse_rotate(stack, operations);
		}
	}
}

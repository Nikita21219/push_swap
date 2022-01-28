/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:45:04 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 09:53:03 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*get_el_with_ind(t_data *stack, int index)
{
	while (index-- && stack->next)
		stack = stack->next;
	return (stack);
}

void	q_sort_helper(t_data **stack, int *r, int pivot, int *left)
{
	while (get_el_with_ind(*stack, *r)->val >= pivot && *left < *r)
		*r -= 1;
	if (*left != *r)
	{
		(get_el_with_ind(*stack, *left))->val = \
		(get_el_with_ind(*stack, *r))->val;
		*left += 1;
	}
	while (get_el_with_ind(*stack, *left)->val <= pivot && *left < *r)
		*left += 1;
	if (*left != *r)
	{
		(get_el_with_ind(*stack, *r))->val = \
		(get_el_with_ind(*stack, *left))->val;
		*r -= 1;
	}
}

void	q_sort(t_data **stack, int left, int r)
{
	int	l_hold;
	int	r_hold;
	int	pivot;

	pivot = get_el_with_ind(*stack, left)->val;
	l_hold = left;
	r_hold = r;
	while (left < r)
		q_sort_helper(stack, &r, pivot, &left);
	get_el_with_ind(*stack, left)->val = pivot;
	pivot = left;
	left = l_hold;
	r = r_hold;
	if (left < pivot)
		q_sort(stack, left, pivot - 1);
	if (r > pivot)
		q_sort(stack, pivot + 1, r);
}

void	free_sort_stack(t_data **stack)
{
	t_data	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	get_mid(t_data *stack)
{
	int		mid;
	t_data	*sort_stack;

	mid = 0;
	sort_stack = NULL;
	while (stack)
	{
		ft_el_add_back(&sort_stack, init(stack->val, 'a'));
		stack = stack->next;
	}
	q_sort(&sort_stack, 0, len_el(sort_stack));
	mid = get_el_with_ind(sort_stack, len_el(sort_stack) / 2)->val;
	free_sort_stack(&sort_stack);
	return (mid);
}

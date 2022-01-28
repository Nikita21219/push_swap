/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scores.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:48:20 by a1                #+#    #+#             */
/*   Updated: 2022/01/27 10:17:19 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_count_even(int *flag, int *count, int count_el)
{
	if (*flag && *count <= count_el / 2)
		*count += 1;
	else
	{
		*flag = 0;
		*count -= 1;
	}
}

void	init_count_odd(int *flag, int *count, t_data *cur, t_data **stack_a)
{
	*count -= 1;
	cur->score = *count + get_score_in_stack_a(stack_a, cur->val);
	*flag = 0;
}

void	init_scores(t_data **stack_a, t_data **stack_b)
{
	int		count;
	int		count_el;
	int		flag;
	t_data	*cur;

	count_el = len_el(*stack_b);
	count = 0;
	flag = 1;
	cur = *stack_b;
	while (cur)
	{
		if (count_el % 2 != 0)
		{
			if (flag && count <= count_el / 2)
				cur->score = count++ + get_score_in_stack_a(stack_a, cur->val);
			else
				init_count_odd(&flag, &count, cur, stack_a);
		}
		else
		{
			init_count_even(&flag, &count, count_el);
			cur->score = count - 1 + get_score_in_stack_a(stack_a, cur->val);
		}
		cur = cur->next;
	}
}

void	sort_logic(t_data **stack_a, t_data **stack_b, t_data **operations)
{
	init_scores(stack_a, stack_b);
	if ((*stack_a)->next->val > (*stack_b)->val && len_el(*stack_a) == 3)
		rotate(stack_a, operations);
	move_element_to_top_stack_b(stack_b, operations);
	move_element_to_top_stack_a(stack_a, stack_b, operations);
	push(stack_b, stack_a, operations);
}

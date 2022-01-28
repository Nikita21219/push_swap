/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:05:44 by a1                #+#    #+#             */
/*   Updated: 2022/01/26 20:07:37 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_score_odd(int *flag, int *count, int count_el, t_data *cur)
{
	if (*flag && *count <= count_el / 2)
	{
		cur->score = *count;
		*count += 1;
	}
	else
	{
		*count -= 1;
		cur->score = *count;
		*flag = 0;
	}
}

void	init_score_even(int *flag, int *count, int count_el, t_data *cur)
{
	if (*flag && *count <= count_el / 2)
		*count += 1;
	else
	{
		*flag = 0;
		*count -= 1;
	}
	cur->score = *count - 1;
}

void	init_scores_a(t_data **stack_a)
{
	int		count;
	int		count_el;
	int		flag;
	t_data	*cur;

	count_el = len_el(*stack_a);
	count = 0;
	flag = 1;
	cur = *stack_a;
	while (cur)
	{
		if (count_el % 2 != 0)
			init_score_odd(&flag, &count, count_el, cur);
		else
			init_score_even(&flag, &count, count_el, cur);
		cur = cur->next;
	}
}

int	get_score_in_stack_a(t_data **stack_a, int val)
{
	t_data	*cur;

	init_scores_a(stack_a);
	cur = *stack_a;
	if (cur->val > val && ft_last_el(*stack_a)->val < val)
		return (cur->score);
	while (cur->next)
	{
		if (cur->val < val && cur->next->val > val)
			return (cur->next->score);
		cur = cur->next;
	}
	return (cur->score);
}

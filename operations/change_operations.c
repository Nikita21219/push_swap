/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:16:11 by a1                #+#    #+#             */
/*   Updated: 2022/01/26 12:30:45 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_continue_rr(t_data *cur)
{
	t_data	*next;

	if ((cur->val == 7 && cur->prev->val == 6 && cur->next->val == 5) || \
	(cur->val == 7 && cur->prev->val == 5 && cur->next->val == 6))
	{
		next = cur->next;
		cur = cur->prev;
		while ((cur->val == 6 && next->val == 5) || \
		(cur->val == 5 && next->val == 6))
		{
			cur->val = -1;
			next->val = 7;
			next = next->next;
			cur = cur->prev;
		}
		cur = next;
		return (1);
	}
	return (0);
}

int	is_continue_ss(t_data *cur)
{
	t_data	*next;

	if ((cur->val == 2 && cur->prev->val == 0 && cur->next->val == 1) || \
	(cur->val == 2 && cur->prev->val == 1 && cur->next->val == 0))
	{
		next = cur->next;
		cur = cur->prev;
		while ((cur->val == 0 && next->val == 1) || \
		(cur->val == 1 && next->val == 0))
		{
			cur->val = -1;
			next->val = 2;
			next = next->next;
			cur = cur->prev;
		}
		cur = next;
		return (1);
	}
	return (0);
}

int	is_continue_rrr(t_data *cur)
{
	t_data	*next;

	if ((cur->val == 10 && cur->prev->val == 9 && cur->next->val == 8) || \
	(cur->val == 10 && cur->prev->val == 8 && cur->next->val == 9))
	{
		next = cur->next;
		cur = cur->prev;
		while ((cur->val == 9 && next->val == 8) || \
		(cur->val == 8 && next->val == 9))
		{
			cur->val = -1;
			next->val = 10;
			next = next->next;
			cur = cur->prev;
		}
		cur = next;
		return (1);
	}
	return (0);
}

void	change_operations(t_data **operations)
{
	t_data	*cur;

	cur = *operations;
	while (cur->next)
	{
		if ((cur->val == 0 && cur->next->val == 1) || \
		(cur->val == 1 && cur->next->val == 0))
			del_opposite_operations(&cur, 2);
		else if ((cur->val == 5 && cur->next->val == 6) || \
		(cur->val == 6 && cur->next->val == 5))
			del_opposite_operations(&cur, 7);
		else if ((cur->val == 8 && cur->next->val == 9) || \
		(cur->val == 9 && cur->next->val == 8))
			del_opposite_operations(&cur, 10);
		cur = cur->next;
		if (is_continue_rrr(cur))
			continue ;
		if (is_continue_rr(cur))
			continue ;
		if (is_continue_ss(cur))
			continue ;
	}
}

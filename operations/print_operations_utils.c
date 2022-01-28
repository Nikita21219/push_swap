/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:40:04 by a1                #+#    #+#             */
/*   Updated: 2022/01/26 12:13:06 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_operation(t_data *current)
{
	if (current->val == 0)
		write(1, "sa\n", 3);
	else if (current->val == 1)
		write(1, "sb\n", 3);
	else if (current->val == 2)
		write(1, "ss\n", 3);
	else if (current->val == 3)
		write(1, "pa\n", 3);
	else if (current->val == 4)
		write(1, "pb\n", 3);
	else if (current->val == 5)
		write(1, "ra\n", 3);
	else if (current->val == 6)
		write(1, "rb\n", 3);
	else if (current->val == 7)
		write(1, "rr\n", 3);
	else if (current->val == 8)
		write(1, "rra\n", 4);
	else if (current->val == 9)
		write(1, "rrb\n", 4);
	else if (current->val == 10)
		write(1, "rrr\n", 4);
}

int	is_rrr(t_data **cur)
{
	if ((*cur)->val == 9 && (*cur)->next->val == 8)
	{
		write(1, "rrr\n", 4);
		(*cur) = (*cur)->next->next;
		return (1);
	}
	else if ((*cur)->val == 8 && (*cur)->next->val == 9)
	{
		write(1, "rrr\n", 4);
		(*cur) = (*cur)->next->next;
		return (1);
	}
	return (0);
}

int	is_rr(t_data **cur)
{
	if ((*cur)->val == 5 && (*cur)->next->val == 6)
	{
		write(1, "rr\n", 3);
		(*cur) = (*cur)->next->next;
		return (1);
	}
	else if ((*cur)->val == 6 && (*cur)->next->val == 5)
	{
		write(1, "rr\n", 3);
		(*cur) = (*cur)->next->next;
		return (1);
	}
	return (0);
}

int	is_ss(t_data **cur)
{
	if ((*cur)->val == 0 && (*cur)->next->val == 1)
	{
		write(1, "ss\n", 3);
		(*cur) = (*cur)->next->next;
		return (1);
	}
	else if ((*cur)->val == 1 && (*cur)->next->val == 0)
	{
		write(1, "ss\n", 3);
		(*cur) = (*cur)->next->next;
		return (1);
	}
	return (0);
}

int	write_and_continue(t_data **cur)
{
	if ((*cur)->next && (*cur)->next->next)
	{
		if (is_rrr(cur))
			return (1);
		if (is_rr(cur))
			return (1);
		if (is_ss(cur))
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:41:18 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/29 20:06:03 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	same_str(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}

void	do_push(char *op, t_data **a, t_data **b, t_data **operations)
{
	if (same_str(op, "pb"))
		push(a, b, operations);
	else if (same_str(op, "pa"))
		push(b, a, operations);
}

void	do_swap(char *op, t_data **a, t_data **b, t_data **operations)
{
	if (same_str(op, "ss"))
	{
		swap(a, operations);
		swap(b, operations);
	}
	else if (same_str(op, "sa"))
		swap(a, operations);
	else if (same_str(op, "sb"))
		swap(b, operations);
}

void	do_rotate(char *op, t_data **a, t_data **b, t_data **operations)
{
	if (same_str(op, "ra"))
		rotate(a, operations);
	else if (same_str(op, "rb"))
		rotate(b, operations);
	else if (same_str(op, "rra"))
		reverse_rotate(a, operations);
	else if (same_str(op, "rrb"))
		reverse_rotate(b, operations);
	else if (same_str(op, "rrr"))
	{
		reverse_rotate(a, operations);
		reverse_rotate(b, operations);
	}
	else if (same_str(op, "rr"))
	{
		rotate(a, operations);
		rotate(b, operations);
	}
}

void	main_logic(t_data **a, t_data **b, t_data **operations, char *buf)
{
	char	*start;

	start = buf;
	while (*buf)
	{
		if (*buf == '\n')
		{
			*buf = 0;
			do_rotate(start, a, b, operations);
			do_push(start, a, b, operations);
			do_swap(start, a, b, operations);
			start = buf + 1;
		}
		buf++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:41:18 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 19:42:39 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_push(char *op, t_data **a, t_data **b, t_data **operations)
{
	if (!ft_strncmp(op, "pb", 2))
		push(a, b, operations);
	else if (!ft_strncmp(op, "pa", 2))
		push(b, a, operations);
}

void	do_swap(char *op, t_data **a, t_data **b, t_data **operations)
{
	if (!ft_strncmp(op, "ss", 2))
	{
		swap(a, operations);
		swap(b, operations);
	}
	else if (!ft_strncmp(op, "sa", 2))
		swap(a, operations);
	else if (!ft_strncmp(op, "sb", 2))
		swap(b, operations);
}

void	do_rotate(char *op, t_data **a, t_data **b, t_data **operations)
{
	if (!ft_strncmp(op, "ra", 2))
		rotate(a, operations);
	else if (!ft_strncmp(op, "rb", 2))
		rotate(b, operations);
	else if (!ft_strncmp(op, "rr", 2))
	{
		rotate(a, operations);
		rotate(b, operations);
	}
	else if (!ft_strncmp(op, "rra", 3))
		reverse_rotate(a, operations);
	else if (!ft_strncmp(op, "rrb", 3))
		reverse_rotate(a, operations);
	else if (!ft_strncmp(op, "rrr", 3))
	{
		reverse_rotate(a, operations);
		reverse_rotate(b, operations);
	}
}

void	apply_oper(char *op, t_data **a, t_data **b, t_data **operations)
{
	if (!ft_strncmp(op, "p", 1))
		do_push(op, a, b, operations);
	else if (!ft_strncmp(op, "s", 1))
		do_swap(op, a, b, operations);
	else if (!ft_strncmp(op, "r", 1))
		do_rotate(op, a, b, operations);
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
			apply_oper(start, a, b, operations);
			start = buf + 1;
		}
		buf++;
	}
}

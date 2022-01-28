/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:37:18 by a1                #+#    #+#             */
/*   Updated: 2022/01/26 12:26:26 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del_opposite_operations(t_data **el, int operation)
{
	(*el)->prev->next = (*el)->next;
	(*el)->next->prev = (*el)->prev;
	(*el)->next->val = operation;
	free(*el);
}

int	is_continue(t_data **c)
{
	t_data	*tmp;

	tmp = *c;
	if ((*c)->next && (*c)->next->next)
	{
		if ((*c)->val == 5 && (*c)->next->val == 8)
			(*c) = (*c)->next->next;
		if ((*c)->val == 8 && (*c)->next->val == 5)
			(*c) = (*c)->next->next;
		if ((*c)->val == 6 && (*c)->next->val == 9)
			(*c) = (*c)->next->next;
		if ((*c)->val == 3 && (*c)->next->val == 4)
			(*c) = (*c)->next->next;
		if ((*c)->val == 4 && (*c)->next->val == 3)
			(*c) = (*c)->next->next;
	}
	if (tmp == *c)
		return (0);
	return (1);
}

void	print_operations(t_data **operations)
{
	t_data	*current;

	current = *operations;
	change_operations(operations);
	while (current)
	{
		if (is_continue(&current))
			continue ;
		else if (write_and_continue(&current))
			continue ;
		print_operation(current);
		current = current->next;
	}
}

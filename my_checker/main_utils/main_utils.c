/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:36:34 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 19:49:19 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_del_elem(t_data **stack, int val)
{
	t_data	*current;

	if (len_el(*stack) == 1)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	current = *stack;
	while (current)
	{
		if (current->val == val)
			del_elem_helper(current, stack);
		current = current->next;
	}
}

t_data	*ft_last_el(t_data *lst)
{
	if (!(lst))
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_el_add_back(t_data **lst, t_data *new)
{
	t_data	*last;

	if (!new)
		return ;
	if (lst && *lst)
	{
		last = ft_last_el(*lst);
		last->next = new;
		new->prev = last;
	}
	else if (lst)
		*lst = new;
}

int	finish_sort(t_data *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_by_two(t_data **stack_a, t_data **operations)
{
	if ((*stack_a)->val > (*stack_a)->next->val)
		swap(stack_a, operations);
}

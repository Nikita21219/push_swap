/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:54:16 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/13 20:30:37 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_el_add_front(t_data **stack, t_data *new)
{
	if (!(new))
		return ;
	if (len_el(*stack) == 0)
	{
		new->next = *stack;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

void	push(t_data **stack_out, t_data **stack_in, t_data **operations)
{
	if (len_el(*stack_out) <= 0)
		return ;
	if ((*stack_out)->c == 'a')
		ft_el_add_front(stack_in, init((*stack_out)->val, 'b'));
	else
		ft_el_add_front(stack_in, init((*stack_out)->val, 'a'));
	if ((*stack_out)->c == 'a')
		ft_el_add_back(operations, init(4, 'b'));
	else
		ft_el_add_back(operations, init(3, 'a'));
	ft_del_elem(stack_out, (*stack_out)->val);
}

void	rotate_two_elements(t_data **stack)
{
	int	tmp;

	tmp = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = tmp;
}

void	rotate(t_data **stack, t_data **operations)
{
	t_data	*last;
	t_data	*tmp;

	if (len_el(*stack) <= 1)
		return ;
	if ((*stack)->c == 'a')
		ft_el_add_back(operations, init(5, (*stack)->c));
	else if ((*stack)->c == 'b')
		ft_el_add_back(operations, init(6, (*stack)->c));
	if (len_el(*stack) > 2)
	{
		tmp = (*stack)->next;
		tmp->prev = NULL;
		last = ft_last_el(*stack);
		(*stack)->prev = last;
		last->next = (*stack);
		(*stack)->next = NULL;
		*stack = tmp;
	}
	else
		rotate_two_elements(stack);
}

void	reverse_rotate(t_data **stack, t_data **operations)
{
	t_data	*last;
	t_data	*tmp;

	if (len_el(*stack) <= 1)
		return ;
	if ((*stack)->c == 'a')
		ft_el_add_back(operations, init(8, (*stack)->c));
	else if ((*stack)->c == 'b')
		ft_el_add_back(operations, init(9, (*stack)->c));
	if (len_el(*stack) > 2)
	{
		last = ft_last_el(*stack);
		last->prev->next = NULL;
		tmp = (*stack);
		tmp->prev = last;
		(*stack) = last;
		(*stack)->prev = NULL;
		(*stack)->next = tmp;
	}
	else
		rotate_two_elements(stack);
}

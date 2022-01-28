/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:02:30 by a1                #+#    #+#             */
/*   Updated: 2022/01/26 12:33:48 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_data **stack, t_data **operations)
{
	int	tmp_val;

	if (len_el(*stack) <= 1)
		return ;
	if ((*stack)->c == 'a')
		ft_el_add_back(operations, init(0, (*stack)->c));
	else if ((*stack)->c == 'b')
		ft_el_add_back(operations, init(1, (*stack)->c));
	tmp_val = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = tmp_val;
}

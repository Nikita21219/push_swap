/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:02:30 by a1                #+#    #+#             */
/*   Updated: 2022/01/27 16:19:56 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

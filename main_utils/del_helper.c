/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:52:22 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 19:52:57 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del_elem_helper(t_data *current, t_data **stack)
{
	if (current == *stack)
	{
		(*stack) = current->next;
		current->next->prev = NULL;
	}
	else if (current == ft_last_el(*stack))
		current->prev->next = NULL;
	else
		current->prev->next = current->next;
	free(current);
}

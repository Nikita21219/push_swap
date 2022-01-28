/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:43:53 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 19:50:20 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	print_result(int res)
{
	if (res == 1)
		write(1, "OK\n", 3);
	else if (res == 0)
		write(1, "KO\n", 3);
	return (0);
}

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

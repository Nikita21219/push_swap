/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:38:54 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/29 18:35:32 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

char	*error_operations(void);
void	main_logic(t_data **a, t_data **b, t_data **operations, char *buf);
int		print_result(int res);
void	del_elem_helper(t_data *current, t_data **stack);
int		final_sort(t_data *stack);

#endif
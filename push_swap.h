/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:38:54 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 20:19:25 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <limits.h>
# include <unistd.h>

typedef struct s_data
{
	int				val;
	int				score;
	char			c;
	struct s_data	*next;
	struct s_data	*prev;
}	t_data;

int		is_error_arg(char **argv);
int		print_error(void);
void	swap(t_data **stack, t_data **operations);
void	ft_el_add_back(t_data **lst, t_data *new);
void	push(t_data **stack_out, t_data **stack_in, t_data **operations);
int		len_el(t_data *stack);
t_data	*init(int val, char c);
t_data	*ft_last_el(t_data *lst);
void	rotate(t_data **stack, t_data **operation);
void	reverse_rotate(t_data **stack, t_data **operation);
void	main_sort(t_data **stack_a, t_data **stack_b, t_data **operations);
int		get_mid(t_data *stack);
int		get_max(t_data *stack);
int		get_min(t_data *stack);
int		is_empty(t_data *stack, int min, int max, int mid);
int		do_not_push(int val, t_data **copy_a, int start_ind, int finish_ind);
void	ft_del_elem(t_data **stack, int val);
int		get_index_with_val(t_data *stack, int val);
void	sort_by_three(t_data **stack_a, t_data **operations);
void	print_operations(t_data **operations);
int		is_sort(t_data *stack);
void	sort_by_two(t_data **stack_a, t_data **operations);
void	print_operation(t_data *current);
int		write_and_continue(t_data **cur);
int		print_error(void);
int		finish_sort(t_data *stack);
void	sort_by_two(t_data **stack_a, t_data **operations);
int		mem_free(t_data *stack);
int		free_stack(t_data *stack);
void	free_stacks(t_data **stack_a, t_data **stack_b, t_data **operations);
int		duplicates_in_stack(t_data *stack);
void	change_operations(t_data **operations);
void	del_opposite_operations(t_data **el, int operation);
void	move_element_to_top_stack_a(t_data **a, t_data **b, t_data **op);
void	move_element_to_top_stack_b(t_data **stack, t_data **operations);
void	init_scores(t_data **stack_a, t_data **stack_b);
int		get_score_in_stack_a(t_data **stack_a, int val);
void	sort_logic(t_data **stack_a, t_data **stack_b, t_data **operations);
void	del_elem_helper(t_data *current, t_data **stack);

#endif
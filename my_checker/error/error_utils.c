/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:47:48 by a1                #+#    #+#             */
/*   Updated: 2022/01/27 16:19:56 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:43:38 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/26 11:49:11 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_not_number(char *arg)
{
	while (*arg)
	{
		if (!(ft_isdigit(*arg)) && *arg != '+' && *arg != '-' && *arg != ' ')
			return (1);
		arg++;
	}
	return (0);
}

long long int	ft_atoi_mod(const char *str)
{
	int				sign;
	long long int	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || \
	*str == '\f' || *str == '\r' || *str == '\x0B')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit((int) *str))
		res = res * 10 + (int) *str++ - '0';
	return (res * sign);
}

int	is_same_lines(char *str1, char *str2)
{
	if (!str1 || !str2 || ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (*str1 && *str2)
	{
		if (*str1++ != *str2++)
			return (0);
	}
	return (1);
}

int	is_duplicates(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (is_same_lines(arr[i], arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_error_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (is_not_number(argv[i]))
			return (1);
		if (ft_atoi_mod(argv[i]) > INT_MAX || ft_atoi_mod(argv[i]) < INT_MIN)
			return (1);
		if (ft_strlen(argv[i]) == 0)
			return (1);
		i++;
	}
	if (is_duplicates(argv))
		return (1);
	return (0);
}

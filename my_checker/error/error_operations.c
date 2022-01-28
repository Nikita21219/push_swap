/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:15:34 by bclarind          #+#    #+#             */
/*   Updated: 2022/01/27 19:30:56 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*mem;
	char	*res;
	char	*tmp_s1;
	char	*tmp_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	mem = ft_calloc(\
		ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1, \
		sizeof(char));
	if (!(mem))
		return (NULL);
	res = mem;
	tmp_s1 = s1;
	tmp_s2 = s2;
	while (*s1)
		*mem++ = *s1++;
	while (*s2)
		*mem++ = *s2++;
	free(tmp_s1);
	return (res);
}

char	*get_buf(void)
{
	char	*buf;
	char	*c;

	buf = malloc(1);
	c = malloc(1);
	while (read(0, c, 1))
		buf = ft_strjoin_free(buf, c);
	free(c);
	return (buf);
}

void	check_operation(char **buf)
{
	if (!ft_strncmp(*buf, "pb\n", 3))
		*buf += 3;
	else if (!ft_strncmp(*buf, "pa\n", 3))
		*buf += 3;
	else if (!ft_strncmp(*buf, "ss\n", 3))
		*buf += 3;
	else if (!ft_strncmp(*buf, "sb\n", 3))
		*buf += 3;
	else if (!ft_strncmp(*buf, "sa\n", 3))
		*buf += 3;
	else if (!ft_strncmp(*buf, "rr\n", 3))
		*buf += 3;
	else if (!ft_strncmp(*buf, "ra\n", 3))
		*buf += 3;
	else if (!ft_strncmp(*buf, "rb\n", 3))
		*buf += 3;
	else if (!ft_strncmp(*buf, "rrr\n", 4))
		*buf += 4;
	else if (!ft_strncmp(*buf, "rra\n", 4))
		*buf += 4;
	else if (!ft_strncmp(*buf, "rrb\n", 4))
		*buf += 4;
}

char	*error_operations(void)
{
	char	*buf;
	char	*result;
	char	*tmp_buf;

	buf = get_buf();
	result = buf;
	while (*buf)
	{
		tmp_buf = buf;
		check_operation(&buf);
		if (tmp_buf == buf)
			return (NULL);
	}
	return (result);
}

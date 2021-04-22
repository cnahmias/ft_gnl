/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:54:16 by cnahmias          #+#    #+#             */
/*   Updated: 2020/07/06 10:17:32 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_len(char *ptr)
{
	int	a;

	a = 0;
	if (ptr == (char *)0)
		return (0);
	while (ptr[a])
		a++;
	return (a);
}

int		ft_search(char *s)
{
	int x;

	if (ft_len(s) == 0)
		return (-1);
	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == '\n')
			return (x);
		x++;
	}
	return (-1);
}

int		get_next_line_bis(int fd, char **line, char **rst, char *buffer)
{
	int cpt;

	buffer = ft_strnew_2(BUFFER_SIZE, buffer);
	while (((cpt = read(fd, buffer, BUFFER_SIZE)) >= 0))
	{
		if ((cpt != BUFFER_SIZE) && (ft_search(buffer) == -1))
		{
			*line = ft_copy(*line, buffer, cpt);
			free(buffer);
			return (0);
		}
		else if (ft_search(buffer) != -1)
		{
			*line = ft_copy(*line, buffer, ft_search(buffer));
			*rst = ft_copy_neg_2(buffer, *rst);
			return (1);
		}
		*line = ft_copy(*line, buffer, cpt);
		buffer = ft_strnew_2(BUFFER_SIZE, buffer);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				i;
	char			*buffer;
	static	char	*rst[1];

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (-1);
	*line = NULL;
	if ((ft_len(*rst) != 0) && (ft_search(*rst) != -1))
	{
		*line = ft_copy(*line, *rst, ft_search(*rst));
		*rst = ft_copy_neg_1(*rst, ft_search(*rst));
		return (1);
	}
	*line = (ft_len(*rst) != 0 ? ft_copy(*line, *rst, -3) : *line);
	free(*rst);
	*rst = NULL;
	buffer = ft_strnew(BUFFER_SIZE);
	i = get_next_line_bis(fd, line, rst, buffer);
	if (i == 0)
		free(*rst);
	return (i);
}

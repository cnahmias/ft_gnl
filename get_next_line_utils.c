/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:54:16 by cnahmias          #+#    #+#             */
/*   Updated: 2020/02/19 18:47:33 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_neg_1(char *s1, int nb)
{
	int		i;
	char	*newline;

	i = 0;
	if (!(newline = (char *)malloc(sizeof(char) * (ft_len(s1) - nb))))
		return ((char *)0);
	while (i < ft_len(s1) - nb - 1)
	{
		newline[i] = s1[nb + i + 1];
		i++;
	}
	newline[i] = '\0';
	free(s1);
	return (newline);
}

char	*ft_copy_neg_2(char *s1, char *s2)
{
	int		i;
	char	*newline;
	int		nb;

	i = 0;
	nb = ft_search(s1);
	if (!(newline = (char *)malloc(sizeof(char) * (ft_len(s1) - nb))))
		return ((char *)0);
	while (i < ft_len(s1) - nb - 1)
	{
		newline[i] = s1[nb + i + 1];
		i++;
	}
	newline[i] = '\0';
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (newline);
}

char	*ft_copy(char *s1, char *s2, int nb)
{
	int		i;
	char	*newline;

	i = 0;
	nb = (nb == -3 ? ft_len(s2) : nb);
	if (!(newline = (char *)malloc(sizeof(char) * (ft_len(s1) + nb + 1))))
		return (NULL);
	while (i < ft_len(s1))
	{
		newline[i] = s1[i];
		i++;
	}
	while (i < ft_len(s1) + nb)
	{
		newline[i] = s2[i - ft_len(s1)];
		i++;
	}
	newline[i] = '\0';
	free(s1);
	return (newline);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strnew_2(size_t size, char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	free(s1);
	return (str);
}

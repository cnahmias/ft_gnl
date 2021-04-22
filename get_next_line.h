/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:35:47 by cnahmias          #+#    #+#             */
/*   Updated: 2020/02/19 15:49:39 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

int		ft_search(char *s);
int		ft_len(char *ptr);
char	*ft_copy_neg_1(char *s1, int nb);
char	*ft_copy_neg_2(char *s1, char *s2);
char	*ft_copy(char *s1, char *s2, int nb);
char	*ft_strnew(size_t size);
char	*ft_strnew_2(size_t size, char *s1);
int		get_next_line(int fd, char **line);
int		get_next_line_bis(int fd, char **line, char **rst, char *buffer);

#endif

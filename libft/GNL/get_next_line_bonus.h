/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:40:24 by jlimones          #+#    #+#             */
/*   Updated: 2022/10/18 17:50:39 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

#  include <unistd.h>
#  include <fcntl.h>
#  include <stdlib.h>
#  include <stdio.h>
#  include <limits.h>
# endif

char	*get_next_line(int fd);
char	*ft_mod_join(char *buff, char *tmp_buff);
char	*ft_get_line(char *buff);
char	*ft_read(int fd, char *buff);
char	*ft_get_static(char *buff);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
void	ft_bzero(void *s, unsigned int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);

#endif
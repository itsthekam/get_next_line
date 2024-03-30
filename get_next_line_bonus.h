/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:10:55 by root              #+#    #+#             */
/*   Updated: 2024/03/30 12:11:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h> //remove

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void	*ft_calloc(size_t size);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, int free_flag);
int		newline_check(char *str);
char	*get_cut_append(char *buf, char **ret);
char	*ft_strcpy(char *str);
char	*get_next_line(int fd);
char	*ft_end(char **ret);
void	free_buf(char *buf);

#endif

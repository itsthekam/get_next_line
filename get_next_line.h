/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-malt <kel-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:06:12 by kel-malt          #+#    #+#             */
/*   Updated: 2024/03/24 18:39:49 by kel-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
char	*ft_strjoin(char *s1, char *s2);
int	newline_check(char *str);
char	*get_cut_append(char *buf, char **ret);
char	*ft_strcpy(char * str);
char	*get_next_line(int fd);




#endif
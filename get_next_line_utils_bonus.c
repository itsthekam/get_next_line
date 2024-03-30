/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:50:57 by root              #+#    #+#             */
/*   Updated: 2024/03/30 12:07:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t size)
{
	void	*ret;
	char	*temp;
	size_t	i;

	i = 0;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	else
	{
		temp = (char *)ret;
		while (i < size)
			temp[i++] = 0;
	}
	return (ret);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	newline_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *str)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = ft_strlen(str);
	ret = ft_calloc(len + 1);
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	free_buf(str);
	return (ret);
}

char	*get_cut_append(char *buf, char **ret)
{
	int		i;
	int		j;
	char	*append;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	append = ft_calloc(i + 2);
	while (j <= i)
	{
		append[j] = buf[j];
		j++;
	}
	*ret = ft_strjoin(*ret, append, 0);
	free(append);
	j = 0;
	i++;
	while (buf[i])
		buf[j++] = buf[i++];
	while (buf[j])
		buf[j++] = 0;
	return (*ret);
}

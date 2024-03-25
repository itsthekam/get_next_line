/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-malt <kel-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:53:08 by kel-malt          #+#    #+#             */
/*   Updated: 2024/03/25 18:04:07 by kel-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (str[i])
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
	return (ret);
}

char	*get_cut_append(char *buf, char **ret)
{
	int		i;
	int		j;
	char	*append;
	char	*cut;

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
	j = 0;
	*ret = ft_strjoin(*ret, append);
	free(append);
	cut = ft_calloc(BUFFER_SIZE - i++ + 1);
	if (!cut)
		return (NULL);
	while (buf[i])
		cut[j++] = buf[i++];
	return (cut);
}

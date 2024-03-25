/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-malt <kel-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:26:16 by kel-malt          #+#    #+#             */
/*   Updated: 2024/03/25 18:04:12 by kel-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	while (s1 && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		s2[i++] = 0;
	free(s1);
	return (ret);
}

char	*get_next_line(int fd)
{
	int				charread;
	char			*buf;
	char			*ret;
	static char		*cut;

	if (fd < 0)
		return (NULL);
	ret = NULL;
	buf = ft_calloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (cut)
	{
		ret = ft_strcpy(cut);
		free(cut);
		cut = NULL;
	}
	while (1)
	{
		charread = read(fd, buf, BUFFER_SIZE);
		if (charread == 0)
		{
			if (!ret || !ret[0])
			{
				free(buf);
				buf = NULL;
				return (NULL);
			}
			break ;
		}
		if (newline_check(buf))
		{
			cut = get_cut_append(buf, &ret);
			if (!cut[0])
			{
				free(cut);
				cut = 0;
			}
			break ;
		}
		if (!ret)
			ret = ft_strcpy(buf);
		else
			ret = ft_strjoin(ret, buf);
	}
	free(buf);
	buf = NULL;
	return (ret);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}

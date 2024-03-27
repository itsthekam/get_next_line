/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-malt <kel-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:26:16 by kel-malt          #+#    #+#             */
/*   Updated: 2024/03/27 19:21:13 by kel-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_end(char *buf, char *ret)
{
	if (buf[0])
		ret = ft_strjoin(ret, buf, 0);
	if (!ret || !ret[0])
	{
		free_buf(buf);
		return (NULL);
	}
	if (buf[0])
		ret = ft_strjoin(ret, buf, 0);
	free_buf(buf);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2, int free_flag)
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
		ret[i++] = s2[j++];
	i = 0;
	while (s2[i])
		s2[i++] = 0;
	free(s1);
	if (free_flag)
		free_buf(s2);
	return (ret);
}

void	free_buf(char *buf)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE + 1)
		buf[i++] = 0;
}

char	*nl_manager(char *buf, char **ret)
{
	*ret = get_cut_append(buf, ret);
	if (!buf[0])
		free_buf(buf);
	return (*ret);
}

char	*get_next_line(int fd)
{
	int			charread;
	static char	buf[BUFFER_SIZE + 1];
	char		*ret;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = NULL;
	if (newline_check(buf))
		return (nl_manager(buf, &ret));
	if (buf[0])
		ret = ft_strcpy(buf);
	while (1)
	{
		charread = read(fd, buf, BUFFER_SIZE);
		if (charread == 0 && !buf[0])
			return (ft_end(buf, ret));
		if (newline_check(buf))
			return (nl_manager(buf, &ret));
		if (buf[0] && !ret)
			ret = ft_strcpy(buf);
		else
			ret = ft_strjoin(ret, buf, 1);
	}
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	fd = open("test", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }

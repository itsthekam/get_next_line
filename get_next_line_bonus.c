/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:51:04 by root              #+#    #+#             */
/*   Updated: 2024/03/30 13:25:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_end(char **ret)
{
	if (!*ret || !*ret[0])
		return (NULL);
	return (*ret);
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
	while (buf[i])
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
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*ret;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	ret = NULL;
	if (newline_check(buf[fd]))
		return (nl_manager(buf[fd], &ret));
	if (buf[fd][0])
		ret = ft_strcpy(buf[fd]);
	while (1)
	{
		charread = read(fd, buf[fd], BUFFER_SIZE);
		if (charread == 0 && !buf[fd][0])
			return (ft_end(&ret));
		if (newline_check(buf[fd]))
			return (nl_manager(buf[fd], &ret));
		if (buf[fd][0] && !ret)
			ret = ft_strcpy(buf[fd]);
		else
			ret = ft_strjoin(ret, buf[fd], 1);
	}
}

// int	main(void)
// {
// 	int		test0;
// 	int		test1;
// 	int		test2;
// 	char	*line;

// 	test0 = open("test", O_RDONLY | O_CREAT);
// 	test1 = open("test1", O_RDONLY | O_CREAT);
// 	test2 = open("test2", O_RDONLY | O_CREAT);

// 	line = "";
// 	while (line != 0)
// 	{
// 		line = (get_next_line(test0));
// 		printf(".%s", line);
// 		free(line);
// 		line = (get_next_line(test1));
// 		printf(".%s", line);
// 		free(line);
// 		line = (get_next_line(test2));
// 		printf(".%s", line);
// 		free(line);
// 	}
// }
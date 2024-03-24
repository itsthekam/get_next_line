#include "get_next_line.h"

void	*ft_calloc(size_t size)
{
	void	*ret;
	char	*temp;
	size_t	i;

	i = 0;
	ret = malloc(size);
	if (!ret)
		return(NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	int		i;
	int		j;
	char		*ret;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = ft_calloc(sizeof(char) * (len1 + len2 + 1));
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
	free(s1);
	return (ret);
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

char	*get_cut_append(char *buf, char **ret)
{
	int	i;
	int	j;
	int	k;
	char	*append;
	char	*cut;

	i = 0;
	j = 0;
	k = 0;
	while (buf[i] != '\n')
		i++;
	append = ft_calloc(i + 2);
	if (!append)
		return (NULL);
	while (j <= i)
	{
		append[j] = buf[j];
		j++;
	}
	*ret = ft_strjoin(*ret, append);
	free(append);
	cut = ft_calloc(BUFFER_SIZE - i + 1);
	if (!cut)
		return (NULL);
	i++;
	while (buf[i])
	{
		cut[k] = buf[i];
		i++;
		k++;
	}
	return (cut);
}

char	*ft_strcpy(char * str)
{
	int	i;
	int	len;
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

char	*get_next_line(int fd)
{
	int			charread;
	char			*buf;
	char			*ret;
	static char	*cut;

	ret = NULL;
	buf = ft_calloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (cut)
	{
		ret = ft_strcpy(cut);
		if (!ret)
			return (NULL);
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
				return (NULL);
			}
			free(buf);
			buf = NULL;
			return (ret);
		}
		if (newline_check(buf))
		{
			cut = get_cut_append(buf, &ret);
			break;
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
	int	fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}
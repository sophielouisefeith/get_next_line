/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:59:23 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/26 16:52:33 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char			*ft_cut(char *new, char **line, int *r)
{
	int		i;
	char	*temp;

	i = 0;
	while (new[i] != '\0' && new[i] != '\n')
		i++;
	*line = ft_substr(new, 0, i);
	if (*line == NULL)
	{
		free(new);
		return (NULL);
	}
	if (new[i] == '\0')
		*r = 0;
	temp = ft_substr(new, i + 1, ft_strlen(new) - i);
	free(new);
	return (temp);
}

static char			*ft_treatment(char *new, int ret, int fd)
{
	char	*buf;

	while (ret > 0)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == 0)
		{
			free(new);
			return (NULL);
		}
		ret = (read(fd, buf, BUFFER_SIZE));
		if (ret == -1)
		{
			free(buf);
			free(new);
			return (NULL);
		}
		buf[ret] = '\0';
		new = ft_strjoin(new, buf);
		if (new == NULL)
			return (NULL);
		if (ft_strchr(new, '\n'))
			break ;
	}
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	int			ret;
	static char *new;
	int			r;

	ret = 1;
	r = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (new == NULL)
		new = ft_strdup("");
	if (new == NULL)
		return (-1);
	new = ft_treatment(new, ret, fd);
	if (new == NULL)
		return (-1);
	new = ft_cut(new, line, &r);
	if (new == NULL)
		return (-1);
	if (r == 0)
	{
		free(new);
		new = 0;
	}
	return (r);
}

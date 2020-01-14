/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:57:40 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/14 19:04:06 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//#define BUFFER_SIZE 100

static char 	*ft_cut(char *new, char **line)
{
	int i;
	
	i = 0;
	while ( new[i] != '\0' && new[i] != '\n')
		i++;
	*line = ft_substr(new, 0, i );
	new = ft_substr(new, i + 1, ft_strlen(new) - i);
	return (new);
}


static int ft_ret(int ret, char *new)
{
	if (ret == 0 && new[0] == '\0')
		return 0;
	if ( ret < 0)
		return -1;
	else 
		return 1;
}

int  get_next_line(const int fd, char **line)
{
	char *buf;
	int ret;
	static char *new;
	
	if (new == NULL)
		new = ft_strdup("");
		if (new == NULL)
			return -1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	ret = 1;
	while (ret)
	{
		ret = (read(fd, buf, BUFFER_SIZE));
    	buf[ret] = '\0';
		new = ft_strjoin(new, buf);
		if (ft_strrchr(new, '\n'))
	 		break ;
	}
	printf("ret[%d]", ret);
 new = ft_cut(new, line);
 ret = ft_ret(ret, new);
 printf("ret[%d]", ret);
 return (ret);
}
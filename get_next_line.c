/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:57:40 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/16 11:43:05 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//#define BUFFER_SIZE 100

static char 	*ft_cut(char *new, char **line)
{
	int i;
	char *temp;
	
	temp = ft_strdup(new);
	i = 0;
	while ( new[i] != '\0' && new[i] != '\n')
		i++;
	*line = ft_substr(new, 0, i );
	free(new);
	if(line <= 0)
		free(*line);
	new = ft_substr(temp, i + 1, ft_strlen(new) - i);
	free(temp);
	if(new <= 0)
		free(new);
	return (new);
}


static int ft_ret(int ret, char **new, char *buf)
{
	if (ret == 0 && *new[0] == '\0')
		return 0;
	if ( ret < 0)
	{
		free(buf);
		free(*new);
		return -1;
	}
	else 
		return 1;
}

int  get_next_line(const int fd, char **line)
{
	char *buf;
	int ret;
	static char *new;
	
	ret = 1;
	if (new == NULL)
		new = ft_strdup("");
		if (new == NULL)
			return (-1);
	while (ret > 0)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == 0)
			return(ft_ret(ret, &new, buf));
		ret = (read(fd, buf, BUFFER_SIZE));
    	buf[ret] = '\0';
		new = ft_strjoin(new, buf);
		if (ft_strchr(new, '\n'))
	 		break ;
	}
 	new = ft_cut(new, line);
 	ret = ft_ret(ret, &new, buf);
 	return (ret);
}
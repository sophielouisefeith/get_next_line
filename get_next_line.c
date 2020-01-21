/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:57:40 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/21 12:08:56 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//#define BUFFER_SIZE 100

static int 	*ft_cut(char **new, char **line)
{
	int i;
	char *temp;

	temp = ft_strdup(*new);
	i = 0;
	if(temp == NULL)
		return(NULL);
	while (*new[i] != '\0' && *new[i] != '\n')
		i++;
	if (new[i] == '\n')
	{
		*line = ft_substr(*new, 0, i );
		if (*line == NULL)
		{
			free(new);
			return(-1);
		}
		
	// if(line <= 0)
	// 	free(*line);
	*new = ft_substr(temp, i + 1, ft_strlen(*new) - i);
	free(temp);
	}
	// if(new <= 0)
	//free(new);
	if (!*line)
		return(-1);
	new = 0;
	return (0);
}

// static int ft_ret(int ret, char *new)
// {
// 	if (ret == 0 && new[0] == '\0')
// 		return 0;
// 	if ( ret < 0)
// 	{
// 		//free(buf);
// 		free(new);
// 		return -1;
// 	}
// 	else 
// 		return 1;
// }

int  get_next_line(const int fd, char **line)
{
	char *buf;
	int ret;
	static char *new;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return(-1);
	ret = 1;
	if (new == NULL)
		new = ft_strdup("");
		if (new == NULL)
			return (-1);
	while (ret > 0)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == 0)
		{
			free(new);
			return(0);
		}
		ret = (read(fd, buf, BUFFER_SIZE));
		if (ret < 0)
		{
			free(buf);
			free(new);
			return(0);
		}
    	buf[ret] = '\0';
		new = ft_strjoin(new, buf);
		if (ft_strchr(new, '\n'))
	 		break ;
	}
	if(!new)
		return(-1);
 	return (*ft_cut(&new, line));
	//  if (new == NULL)
	//  	return(-1);
 	//ret = -1;
 	// return (ret);
}
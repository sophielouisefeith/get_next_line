/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:57:40 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/14 15:51:50 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//#define BUFFER_SIZE 100

static char 	*ft_cut(char *new, char **line)
{
	int i;
	
	// i = ft_strlen(new);
	// while (i >= 0 && new[i] != '\0' && new[i] != '\n' )
	// {
	// 	i--;
	// 	// break ;
	// 	//i++;
	// }
	i = 0;
	while ( new[i] != '\0' && new[i] != '\n')
		i++;
	*line = ft_substr(new, 0, i );
	new = ft_substr(new, i + 1, ft_strlen(new) - i);
	return (new);
}


static int ft_ret(int ret)
{
	if (ret > 0)
		return 1;
	else
		return ret;
}

int  get_next_line(const int fd, char **line)
{
	char *buf;
	int ret;
	static char *new;
	
	if (new == NULL)
		new = ft_strdup("");
	buf = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	ret = 1;
	while (ret)
	{
		ret = (read(fd, buf, BUFFER_SIZE));
    	buf[ret] = '\0';
		new = ft_strjoin(new, buf);
		// if (ft_strlen(new) > BUFFER_SIZE)
		// {
		if (ft_strrchr(new, '\n'))
	 		break ;
		if (!ft_strrchr(new ))
			//new = ft_cut(new, line);
		// }
		// if (ft_strlen(new) > BUFFER_SIZE)
		// {
		// 	if (ft_strrchr(new, '\n'))
	 	// 		break ;
		// 	new = ft_cut(new, line);
		// }
	}
 new = ft_cut(new, line);
 ret = ft_ret(ret);
 return (ret);
}
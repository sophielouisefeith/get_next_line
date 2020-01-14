/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:57:40 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/14 14:52:05 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 100

// functie voordat je de while inloopt wat zit er in de line zitten hier nog new lines in 

static char 	*ft_cut(char *new, char **line )
{
	int i;
	
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
	//int round;

	//round = 0;
	if (new == NULL)
		new = ft_strdup("");
	buf = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	// wat zit er in new en zo ja zit er in new line is 
	ret = 1;
	while (ret)
	{
		ret = (read(fd, buf, BUFFER_SIZE));
    	buf[ret] = '\0';
		//printf("buf[%s]\n", buf);
		new = ft_strjoin(new, buf);
		//printf("join[%s]\n", new);
		if (ft_strchr(new, '\n'))
		{
			//printf("break[%s]\n", new);
	 		break ;
		}
	//round ++;
	}
 new = ft_cut(new, line);
 //printf("round[%d]", round);
 //printf("break[%s]\n", new);
 ret = ft_ret(ret);
 return (ret);
}






// eerst wil ik een line lezen en daarna printen      fd    ** char  *next_line *str

//line = (char *)malloc(sizeof(char) * (BUFFER_SIZE));

// eert willen we dus een lijn gaan lezen tot het eind tekekeken
// dat stukje willen we opslaan 
// en dan willen we naar de volgende lijn 

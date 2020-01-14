/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_getnextline.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 11:44:42 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/14 14:42:47 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"



int     main(void)
{
    int fd;
    int ret;
	char *line;
    //char buf[BUFFER_SIZE + 1];
	int i = 0;
	
	ret = 1;
    fd = open("text.txt", O_RDONLY);
	if (fd == - 1)
		printf("mislukt[%d]", fd);
    while( ret > 0 )
	{
		ret = get_next_line(fd, &line);
     	//printf("line: [%s]\n", line);
		printf("PRINT: [%i] [%s]\n", i, line);
		i++;
	}
			
    //ret = read(fd, buf, BUFFER_SIZE);
   // buf[ret] = '\0';
    //printf("ret: [%d]\n", ret);
   // printf("buf:\n[%s]\n", buf);
}




	
	// int		res;
	// int		fd;
	// int		i;
	// char	*line;

	// i = 1;
	// res = 1;
	// fd = open(argv[1], O_RDONLY);
	// while (res == 1)
	// {
	// 	res = get_next_line(fd, &line);
	// 	printf("--%d--", i);
	// 	printf("%s", line);
    //     printf("\n");
    //     i++;
    //     free(line);
    // }
    // while (1){}
     //return (0);

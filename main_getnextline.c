/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_getnextline.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:59:23 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/22 18:21:40 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


int     main(void)
{
    int fd;
    int ret;
	char *line;
    //char buf[BUFFER_SIZE + 1];
	int i = 1;
	
	ret = 1;
    fd = open("text.txt", O_RDONLY);
	if (fd == - 1)
		printf("mislukt[%d]", fd);
    while( ret > 0)
	{
		ret = get_next_line(fd, &line);
     	//printf("line: [%s]\n", line);
		printf("PRINT: [%i] [%d] [%s]\n", i, ret, line);
		free(line);
		i++;
		//free(line);
	}
	// while(1)
	// {
		
	// }
}


// int     main(int argc, char **argv)
// {
//     int fd1;
//     //int fd2;
//     int fd3;
//     char *line;
//     int ret;
    
//     fd1 = open("tekst.txt", O_RDONLY); //invald file "24"
//     //fd2 = open("bible.txt",O_RDONLY);
//     if (argc > 1)
//         fd3 = open(argv[1], O_RDONLY);
//     // if (fd1 == -1)
//     // {
//     //  printf("Error Number [% d]\n", errno);
//     //  perror("Program");
//     // }
//     ret = 1;
//     while (ret > 0)
//     {
//         ret = get_next_line(fd1, &line);
//         //printf("1.Adres van line: [%p]\n", &line);
//         //printf("1.Adres van line: [%p]\n", line); //wat is dit dan voor adres?
//         //printf("-----Back in main----\n");
//         printf("Return:[%i] - line = [%s]\n", ret, line);
//         free(line);
//     }
//     // while (1){}
//     return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:30:54 by irodrigo          #+#    #+#             */
/*   Updated: 2019/12/11 12:33:19 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;
	int 	i;

	line = 0;
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			printf("%d- archivo: %s\n",i, argv[i]);
			while ((ret = get_next_line(fd, &buff)) > 0)
			{
				printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
				free(buff);
			}
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			if (ret == -1)
				printf("-----------\nError\n");
			else if (ret == 0)
				printf("-----------\nEnd of file\n");
			free(buff);
		}
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of stdin\n");
		free(buff);
		close(fd);
	}
	return (0);
}

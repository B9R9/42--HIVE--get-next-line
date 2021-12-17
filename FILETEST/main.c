/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:33:18 by briffard          #+#    #+#             */
/*   Updated: 2021/12/17 15:50:11 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i = 0;
	int		j = 0;

	line = NULL;

	fd = 0;
	if (argc == 1)
	{
		while(get_next_line(0, &line) > 0)
		{
			ft_putstrcolor(line,"yellow");
			ft_putchar('\n');
			free(line);
		}
	}
	else if (argc > 1)
	{
		/*MULTIPLE FD TEST*/
		int mfd[5] = {0, 0, 0,0, 0};

		mfd[0] = open(argv[1], O_RDONLY);
		mfd[1] = open(argv[2], O_RDONLY);
		mfd[2] = open(argv[3], O_RDONLY);
		mfd[3] = open(argv[4], O_RDONLY);
		mfd[4] = open(argv[5], O_RDONLY);

		while(j < 6)
			{
				i = 0;
				while((get_next_line(mfd[i], &line) > 0))
				{
					ft_putstrcolor(line, "yellow");
					ft_putchar('\n');
					i++;
				}
			j++;
			}
	}
	else
	{
			fd = open(argv[1], O_RDONLY);
			while((get_next_line(fd, &line) > 0))
				{	
					ft_putstrcolor(line,"yellow");
					ft_putchar('\n');
					free(line);
				}
		}
	close(fd);

	//free(line);
	//system("leaks test_gnl");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:33:18 by briffard          #+#    #+#             */
/*   Updated: 2021/12/14 15:43:53 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	line = NULL;

	fd = 0;
	if (argc == 1)
	{
		while(get_next_line(0, &line) > 0)
		{
			ft_putstrcolor(line,"yellow");
			ft_putchar('\n');
		}
	}
	else
	{
			fd = open(argv[1], O_RDONLY);
			while((get_next_line(fd, &line) > 0))
				{	
					ft_putstrcolor(line,"yellow");
					ft_putchar('\n');
				}
		}
	free(line);
}

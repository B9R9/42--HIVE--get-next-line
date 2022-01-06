/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:33:18 by briffard          #+#    #+#             */
/*   Updated: 2022/01/06 13:05:36 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int     fd;

	if (argc < 2)
		(void)(argv);

	line = NULL;
	fd = open("./TestFiles/basictest8c1L.txt", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	ft_color(NORMAL);
	ft_putstr("Print 1 line of 8 characters : ");
	if (!ft_strcmp(line, "abcedefi"))
		ft_putstrcolor("OK\n","green");
	else
		ft_putstrcolor("KO\n", "red");
	
	fd = open("./TestFiles/basictest8c2L.txt", O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr("Print 2 lines of 8 characters: ");
	if (!ft_strcmp(line,"qwertyui"))
		ft_putstrcolor("Line 1 OK ", "green");
	else
		ft_putstrcolor("Line 1 KO ", "red");
	get_next_line(fd, &line);
	if (!ft_strcmp(line,"asdfghjk"))
		ft_putstrcolor("Line 2 OK\n", "green");
	else
		ft_putstrcolor("Line 2 KO\n", "red");
	close(fd);
	fd = open ("./TestFiles/basictest8cxL.txt", O_RDONLY);
	int i = 1;
	char	*basictest8cxl[]= {"0", "qwertyui","asdfghjk", "zxcvbnm,", "qazwsxed", "poiuytre", "lkjhgfds", "mnbvcxzl"};
	ft_putstr("Print Multiple lines of 8 characters: ");
	while(get_next_line(fd, &line) > 0)
	{
		if (!ft_strcmp(line, basictest8cxl[i]))
		{
			ft_putstrcolor("Line ","green");
			ft_putnbr(i);
			ft_putstrcolor (" OK ", "green");
			i++;
		}
		else
		{
			ft_putstrcolor("Line ", "red");
			ft_putnbr(i);
			ft_putstrcolor(" KO ", "red");
			i++;
		}
	}
	close(fd);
}

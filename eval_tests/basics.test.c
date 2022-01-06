/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:33:18 by briffard          #+#    #+#             */
/*   Updated: 2022/01/06 21:19:45 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int     fd;

	if (argc == 1)
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
	if (argc == 2)
	{
		ft_putstrcolor("======================================================= DETAILS\n", "cyan");
		ft_putstr("RETURN EXPECTED   : abcedefi\n");
		printf("RETURN OF GNL     : %s\n", line);
		ft_putstrcolor("===============================================================\n","cyan");
	}

	char	*saveline[] = {"0","0"};
	fd = open("./TestFiles/basictest8c2L.txt", O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr("Print 2 lines of 8 characters: ");
	if (!ft_strcmp(line,"qwertyui"))
		ft_putstrcolor("Line 1 OK ", "green");
	else
		ft_putstrcolor("Line 1 KO ", "red");
	if (argc == 2)
		 saveline[0] = ft_strdup(line);
	get_next_line(fd, &line);
	if (!ft_strcmp(line,"asdfghjk"))
		ft_putstrcolor("Line 2 OK\n", "green");
	else
		ft_putstrcolor("Line 2 KO\n", "red");
	if (argc == 2)
	{
		saveline[1] = ft_strdup(line);
		ft_putstrcolor("======================================================= DETAILS\n", "cyan");
		ft_putstr("RETURN EXPECTED   : LINE 1 -> qwertyui\n");
		ft_putstr("                    LINE 2 -> asdfghjk\n");
		printf("RETURN OF GNL     : LINE 1 -> %s\n",saveline[0]);
		printf("                    LINE 2 -> %s\n",saveline[1]);
		ft_putstrcolor("===============================================================\n", "cyan");
	}
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

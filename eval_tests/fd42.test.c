/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd42.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:33:18 by briffard          #+#    #+#             */
/*   Updated: 2022/01/07 12:13:04 by briffard         ###   ########.fr       */
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
	fd = open("./TestFiles/advancedtest4c1L.txt", O_RDONLY);
	get_next_line(42, &line);
	close(fd);
	ft_color(NORMAL);
	ft_putstr("Print 1 line of 4 characters and passing FD = 42:\n ");
	if (!ft_strcmp(line, "asdf"))
		ft_putstrcolor("OK\n","green");
	else
		ft_putstrcolor("KO\n", "red");
	if (argc == 2)
	{
		ft_putstrcolor("======================================================= DETAILS\n", "cyan");
		ft_putstr("RETURN EXPECTED   : asdf\n");
		printf("RETURN OF GNL     : %s\n", line);
		ft_putstrcolor("===============================================================\n\n","cyan");
	}
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:34:00 by briffard          #+#    #+#             */
/*   Updated: 2021/12/14 15:43:28 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	int			i;

	i = 0;
	//sleep(1);
	/*CHECK LES ERREURS*/
	if(fd == -1 || !line)
		return (-1);
	/*faire le malloc que si str ne contient rien*/
	if (!str)
	{
		str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1 ));
		if (!str)
			{
				ft_putstrcolor("ERREUR MALLOC STR\n", "red");
				return(-1);
			}
	}
	/*COPIE BUFFER DANS STR*/
	while((ret = read(fd,&buffer,BUFF_SIZE)) > 0)
		{
			buffer[ret] = '\0';
			str = ft_strjoin(str, buffer);
		}
	//free(buffer);
	/*LOOK FOR THE LINE*/
	if(str[i])
	{
		while(str[i] != '\n' && str[i] != '\0')
			i++;
		if( i == 0)
			*line = ft_strdup("");
		else
			*line = ft_strsub(str, 0, i);
		str = &str[i + 1];
		return(1);
	}
	else
		*line = ft_strdup("");
	//printf("%p\n", str);
	//ft_strdel(&str);
	//system("leaks ./test_gnl");
	return(0);
}

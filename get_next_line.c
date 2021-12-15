/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:34:00 by briffard          #+#    #+#             */
/*   Updated: 2021/12/15 17:53:36 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buffer[BUFF_SIZE + 1];
	char		*temp = NULL;
	int			ret;
		;
	int			i;

	i = 0;

	//sleep(1);
	/*CHECK LES ERREURS*/
	if(fd < 0 || !line)
		return (-1);
	if (BUFF_SIZE == 0)
	{
		*line = NULL;
		return(-1);
	}
/****************************************************************************	
	while(get_index_line(buffer[fd]) == -1)
	{

		ft_bzero(buffer[fd], BUFF_SIZE + 1);
		ret =(fd, buffer[fd], BUFF_SIZE);
	}
*******************************************************************************/
	if (!str)
	{
		ret = 1;
		str = (char *)malloc(sizeof(char)* BUFF_SIZE + 1);
		/*COPIE BUFFER DANS STR*/
		while(ret > 0)
			{
				ret = read(fd, &buffer, BUFF_SIZE);
				buffer[ret] = '\0';
				temp = ft_strjoin(str, buffer);
				free(str);
				str = temp;
			}
	}
	//DO I have to clear the buffer ??
	/*LOOK FOR THE LINE*/
	if(str[i])
	{
		while(str[i] != '\n' && str[i] != '\0')
			i++;
		if( i == 0)
			*line = ft_strdup("");
		else
			*line = ft_strsub(str, 0, i);
		ft_bzero(str, i);
		str = &str[i + 1];
		return(1);
	}
	else
		*line = ft_strdup("");
	//ft_strdel(&str);// Created a free pointer problem
	//free(line); This created a Free pointer problem
	return(0);
}

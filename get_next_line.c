/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:34:00 by briffard          #+#    #+#             */
/*   Updated: 2021/12/17 15:50:22 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;
	int			i;

	i = 0;
	temp = NULL;
	/*CHECK LES ERREURS*/
	if(fd < 0 || !line || read(fd, buffer,0) < 0)
		return (-1);
	if (BUFF_SIZE <= 0)
	{
		*line = NULL;
		return (-1);
	}
	if (!str[fd])
	{	
		str[fd] = ft_strnew(0);
	/*COPIE BUFFER DANS STR*/
		ret = 1;
		while(ret > 0)
		{	
			ret = read(fd,&buffer,BUFF_SIZE);
			buffer[ret] = '\0';
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
}
	//free(temp);// Change the return
	/*LOOK FOR THE LINE*/
	if(str[fd][i])
	{
		while(str[fd][i] != '\n' && str[fd][i] != '\0')
			i++;
		if( i == 0)
			*line = ft_strdup("");
		else
			*line = ft_strsub(str[fd], 0, i);
		str[fd] = &(str[fd][i + 1]);
		return(1);
	}
	return(0);
}

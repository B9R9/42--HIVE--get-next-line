/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:52:18 by briffard          #+#    #+#             */
/*   Updated: 2021/12/23 14:39:27 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	check_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static int	ft_print_line(char **str, char **line)
{
	char	*temp;
	int		i;

	i = check_eol(*str);
	if ((*str)[i] == '\n')
	{
		*line = ft_strsub(*str, 0, i);
		temp = ft_strdup(&(*str)[i + 1]);
		if (!line || !temp)
			return (-1);
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	ft_check_return(char **str, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !str[fd])
		return (0);
	return (ft_print_line(&str[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	ret = read(fd, buffer, BUFF_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		ret = read(fd, buffer, BUFF_SIZE);
	}
	return (ft_check_return(str, line, ret, fd));
}

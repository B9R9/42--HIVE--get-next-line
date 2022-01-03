/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:52:18 by briffard          #+#    #+#             */
/*   Updated: 2021/12/29 14:45:13 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_print_line(char **str, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_strsub(*str, 0, i);
		temp = ft_strdup(&((*str)[i + 1]));
		if (!line || !temp)
			return (-1);
		ft_memdel((void **)(&(*str)));
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

static char	*add_buffer_to(char **str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*str, buffer);
	if (!temp)
		return (NULL);
	ft_memdel((void **)(&(*str)));
	*str = temp;
	return (*str);
}

static int	error_check(int fd, char **str, char **line)
{
	if (fd < 0 || !line || BUFF_SIZE <= 0 || fd > FD_SIZE)
		return (-1);
	if (!(*str))
	{
		*str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		if (!(*str))
			return (-1);
		ft_bzero(*str, BUFF_SIZE);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	int			ret;

	if (error_check(fd, &str[fd], line))
		return (-1);
	if (str[fd] && ft_strchr(str[fd], '\n'))
		return (ft_print_line(&str[fd], line));
	else
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == 0)
			return (0);
		while (ret > 0)
		{
			buffer[ret] = '\0';
			str[fd] = add_buffer_to(&str[fd], buffer);
			if (str[fd] == NULL)
				return (-1);
			if (ft_strchr(str[fd], '\n'))
				break ;
			ret = read(fd, buffer, BUFF_SIZE);
		}
	}
	return (ft_check_return(str, line, ret, fd));
}

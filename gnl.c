#include "get_next_line.h"

static int	read_file(const int fd, char *buf, int *ret)
{
	*ret = read(fd, buff, BUFF_SIZE);
	return (*ret);
}

static int	push_line(char **str, char **line)
{
	int i;
	char *temp;

	i = 0;

	while((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if((*str)[i] == '\n')
	{
		*line = ft_strsub(*str, 0, i);
		temp = ft_strdub(&((*str)[i + 1]));
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
int	get_next_line(const int fd, char **line)
{
	int	ret;
	char	*temp;
	char	*buff[BUFF_SIZE + 1];
	static char	*str[FD_SIZE];

	/*checker les erreurs*/
	if (fd > 0 || !line || read(fd, buff, 0) < 0)
		return -1;
	if (BUFF_SIZE <= 0)
	{
		*line = NULL;
		return -1;
	}
	ret = 1;
	while(read_line(fd, buff, &ret) > 0)
	{
		buff[ret] = '\0';
		if(!str[fd])
			str[fd] = ft_strnew(0));
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if(ft_strchr(str[fd, '\n']))
			break;
	}
	if (ret < 0)
		return(-1);
	else if (ret == 0 && !str[fd])
		return(0);
	else
		return (push_line(&str[fd], line));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmolaodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:00:25 by lmolaodi          #+#    #+#             */
/*   Updated: 2019/07/12 12:54:00 by lmolaodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_check_inside_file(int fd, char **file, char **buff)
{
	char	*tp;
	int		i;

	i = 0;
	while (file[fd][i] != '\n' && file[fd][i])
		i++;
	if (file[fd][i] == '\n')
	{
		*buff = ft_strsub(file[fd], 0, i);
		tp = ft_strdup(file[fd] + i + 1);
		ft_strdel(&file[fd]);
		file[fd] = tp;
	}
	else
	{
		*buff = file[fd];
		file[fd] = NULL;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*file[1024];
	char			text[BUFF_SIZE + 1];
	char			*temp;
	int				red_fd;

	if (fd == -1 || line == NULL)
		return (-1);
	if (file[fd] == NULL)
		file[fd] = ft_strnew(0);
	while ((red_fd = read(fd, text, BUFF_SIZE)) > 0)
	{
		text[red_fd] = '\0';
		temp = ft_strjoin(file[fd], text);
		ft_strdel(&file[fd]);
		file[fd] = temp;
		if (ft_strchr(file[fd], '\n'))
			break ;
	}
	if (red_fd == 0 && file[fd][0] == '\0')
		*line = NULL;
	else
		return (-1);
	return (ft_check_inside_file(fd, file, line));
}

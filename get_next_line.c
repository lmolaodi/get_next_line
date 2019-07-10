/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmolaodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:00:25 by lmolaodi          #+#    #+#             */
/*   Updated: 2019/07/10 15:14:14 by lmolaodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	ft_check_inside_file(int fd, int red_fd, char **file, char **buff)
{
	int i;
	char	*tp;

	i = 0;
	while ((file[fd][i] != '\0' && file[fd][i] != '\n'))
		i++;
	if (file[fd][i] == '\n')
	{
		*buff = ft_strsub(file[fd], 0, i);
		tp = ft_strdup(file[fd] + i + 1);
		free(file[fd]);
		file[fd] = tp;
	}
	if(file[fd][i] == '\0')
	{
		if (red_fd == BUFF_SIZE)
			return (get_next_line(fd, buff));
		*buff = file[fd];
		ft_strclr(file[fd]);
	}
	if (file == 0 || file[fd][i] == '\0')
		return (0);
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
		free(file[fd]);
		file[fd] = temp;
		if (ft_strchr(file[fd], '\n'))
			break ;
	}
	if (red_fd == 0 && file[fd] == '\0')
		return (0);
	return (ft_check_inside_file(fd, red_fd, file, line));
}

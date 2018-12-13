/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:59:13 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/13 18:02:08 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_zap(const int fd, char **line, char **a)
{
	char	*str;
	int		i;

	i = 0;
	while (a[fd][i] != '\n' && a[fd][i] != '\0')
		i++;
	if (a[fd][i] == '\n')
	{
		*line = ft_strsub(a[fd], 0, i);
		str = ft_strdup(a[fd] + i + 1);
		free(a[fd]);
		a[fd] = str;
	}
	else
	{
		*line = ft_strdup(a[fd]);
		ft_strdel(&a[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*a[9999];
	char		*str;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (a[fd] == NULL)
		a[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoinre(a[fd], buf);
		a[fd] = str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!a[fd] || !ft_strexist(a[fd])))
		return (0);
	return (ft_zap(fd, line, a));
}

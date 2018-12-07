/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:11:01 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/07 18:43:54 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_zap(char *buf, char **line, char **list)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		buf[i++] = '\0';
	*line = ft_strjoinre(*line, buf);
	*list = ft_strcpy(*list, buf + i);
	if (!line || !list)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*list = NULL;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!list)
		list = ft_strnew(0);
	*line = ft_strnew(0);
	if (ft_strlen(list) > 0)
		if (ft_strchr(list, '\n') != NULL && ft_zap(list, line, &list) == -1)
			return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ft_strchr(buf, '\n') != NULL)
		{
			if (ft_zap(buf, line, &list) == -1)
				return (-1);
			break ;
		}
		buf[ret] = '\0';
		*line = ft_strjoinre(*line, buf);
	}
	if (ret == 0 && !ft_strchr(list, '\n'))
		return (0);
	return (1);
}

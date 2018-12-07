/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:54:20 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/30 18:36:38 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcat(char *dst, const char *app)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!app && !dst)
		return (NULL);
	while (dst[i] != '\0')
		i++;
	while (app[k] != '\0')
		dst[i++] = app[k++];
	dst[i] = '\0';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:58:38 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/30 20:45:52 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*s;
	int					i;
	unsigned int		k;

	k = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((s = (char *)malloc(sizeof(s) * (i + 1))) == NULL)
		return (NULL);
	while (*s1)
		s[k++] = *s1++;
	while (*s2)
		s[k++] = *s2++;
	s[k] = '\0';
	return (s);
}

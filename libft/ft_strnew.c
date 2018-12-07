/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:49:52 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/30 18:38:01 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	if (size == (size_t)(-1))
		return (NULL);
	a = (char *)malloc(size + 1);
	if (a == NULL)
		return (NULL);
	ft_memset(a, (int)'\0', size + 1);
	return (a);
}

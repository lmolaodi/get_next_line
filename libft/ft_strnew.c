/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmolaodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:00:56 by lmolaodi          #+#    #+#             */
/*   Updated: 2019/07/16 12:40:26 by lmolaodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	if (!(newstr = ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		newstr[i++] = '\0';
	}
	return (newstr);
}

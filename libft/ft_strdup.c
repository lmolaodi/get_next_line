/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmolaodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:30:01 by lmolaodi          #+#    #+#             */
/*   Updated: 2019/07/16 12:34:52 by lmolaodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(*s1) * ft_strlen(s1) + 1);
	if (new)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}

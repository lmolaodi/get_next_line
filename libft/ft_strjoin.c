/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmolaodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:19:27 by lmolaodi          #+#    #+#             */
/*   Updated: 2019/07/16 12:36:28 by lmolaodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (str)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		str[len++] = '\0';
		return (str);
	}
	return (0);
}

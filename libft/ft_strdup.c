/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:32:57 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/17 19:51:03 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;
	char	*str1;

	str1 = (char *)s1;
	i = 0;
	s2 = (char *)malloc (sizeof(char) * (ft_strlen(str1) +1));
	if (s2 == NULL)
		return (0);
	while (str1[i] != '\0')
	{
		s2[i] = str1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

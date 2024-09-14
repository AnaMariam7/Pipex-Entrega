/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:05:03 by anmaher-          #+#    #+#             */
/*   Updated: 2024/08/03 13:05:04 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	p;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		p = 0;
		while (haystack[i + p] == needle[p] && (i + p) < len)
		{
			if (needle[p + 1] == '\0')
				return ((char *)&haystack[i]);
			p++;
		}
		i++;
	}
	return (0);
}

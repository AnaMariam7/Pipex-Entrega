/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:23:39 by anmaher-          #+#    #+#             */
/*   Updated: 2024/08/03 12:59:02 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;
	char	*src1;

	src1 = (char *)src;
	x = ft_strlen(src1);
	i = 0;
	if (dstsize != 0)
	{
		while (src1[i] != '\0' && i < dstsize -1)
		{
			dst[i] = src1[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (x);
}

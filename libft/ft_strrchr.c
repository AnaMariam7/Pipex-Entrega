/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:36:39 by anmaher-          #+#    #+#             */
/*   Updated: 2024/08/03 13:06:20 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	a;

	str = (char *)s;
	a = (char)c;
	i = ft_strlen(str);
	if (str[i] == a)
		return (&str[i]);
	i--;
	while (i >= 0)
	{
		if (str[i] == a)
			return (&str[i]);
		i--;
	}
	return (0);
}
/*int main(void)
{
	int c;
	c = 'l';
	const char str[]= "Hola lola";
	printf("%s", ft_strrchr(str, c));
	printf("%s", strrchr(str, c));
}*/

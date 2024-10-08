/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:57:26 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/17 20:57:31 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo1;

	nodo1 = malloc(sizeof(t_list));
	if (!nodo1)
		return (0);
	nodo1->content = content;
	nodo1->next = NULL;
	return (nodo1);
}

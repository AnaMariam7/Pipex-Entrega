/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:57:52 by bargarci          #+#    #+#             */
/*   Updated: 2024/07/01 23:10:01 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*nodo;
	size_t	i;

	i = 0;
	nodo = lst;
	while (nodo != NULL)
	{
		nodo = nodo->next;
		i++;
	}
	return (i);
}

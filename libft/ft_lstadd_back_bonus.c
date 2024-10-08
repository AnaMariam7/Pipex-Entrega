/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:50:30 by anmaher-          #+#    #+#             */
/*   Updated: 2024/07/01 23:14:55 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nodotemp;

	if (!new)
		return ;
	nodotemp = *lst;
	if (!nodotemp)
		*lst = new;
	else
	{
		while (nodotemp->next != NULL)
			nodotemp = nodotemp->next;
		nodotemp->next = new;
	}
}

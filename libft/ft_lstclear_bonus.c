/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:11:57 by user              #+#    #+#             */
/*   Updated: 2022/10/04 09:46:16 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*next;

	list = *lst;
	if (list && del)
	{
		while (list)
		{
			next = list->next;
			del(list->content);
			free(list);
			list = next;
		}
	}
	*lst = NULL;
}

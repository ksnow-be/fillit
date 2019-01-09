/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:11:36 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/12/03 16:37:50 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmpnext;

	if (!alst || !del)
		return ;
	tmp = *alst;
	while (tmp)
	{
		tmpnext = tmp->next;
		del((tmp->content), (tmp->content_size));
		free(tmp);
		tmp = tmpnext;
	}
	*alst = NULL;
}

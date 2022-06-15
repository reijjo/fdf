/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:34:13 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/27 17:10:28 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;

	if (lst == NULL)
		return (NULL);
	fresh = (t_list *)malloc(sizeof(t_list));
	if (fresh == NULL)
		return (NULL);
	if (lst && f)
	{
		fresh = f(lst);
		if (fresh && lst->next)
			fresh->next = ft_lstmap(lst->next, f);
		return (fresh);
	}
	return (NULL);
}

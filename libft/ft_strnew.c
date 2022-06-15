/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:48 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/17 16:48:07 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	fresh = (char *)malloc(sizeof(char) * (size + 1));
	if (fresh == NULL)
		return (NULL);
	ft_bzero(fresh, size + 1);
	return (fresh);
}

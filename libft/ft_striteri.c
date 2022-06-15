/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:50:00 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/27 17:33:05 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int				i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(k, &s[i]);
			k++;
			i++;
		}
	}
}

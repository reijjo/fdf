/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:04:03 by taitomer          #+#    #+#             */
/*   Updated: 2021/12/02 21:01:41 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;
	int		len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		fresh[i] = f(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}

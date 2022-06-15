/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:39:48 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/18 13:36:57 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_long(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*fresh;
	int		i;
	int		len;

	len = how_long(n);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (fresh == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		fresh[0] = '-';
		n = -n;
	}
	else if (n == 0)
		fresh[0] = '0';
	i = len - 1;
	while (n != 0 && i >= 0)
	{
		fresh[i--] = n % 10 + '0';
		n = n / 10;
	}
	fresh[len] = '\0';
	return (fresh);
}

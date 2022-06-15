/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:26:55 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/22 12:52:07 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	word = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			word = 0;
		else if (word == 0)
		{
			word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	word_length(char const *str, int i, char c)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	fresh = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (fresh == NULL)
		return (NULL);
	while (s[i] != '\0' && j < count_words(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		fresh[j] = (char *)malloc(sizeof(char) * word_length(s, i, c) + 1);
		while (s[i] != c && s[i] != '\0')
			fresh[j][k++] = s[i++];
		fresh[j][k] = '\0';
		j++;
	}
	fresh[j] = 0;
	return (fresh);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:52:46 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/01 19:52:47 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_freemem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	**ft_fillarr(char const *s, char c, int words, char **res)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		res[j] = ft_substr(s, i - len, len);
		if (res[j] == NULL)
			return (ft_freemem(res));
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (s == NULL)
		return (NULL);
	words = ft_words(s, c);
	res = ft_calloc((words + 1), sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (ft_fillarr(s, c, words, res));
}

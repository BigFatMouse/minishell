/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:53:00 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/01 19:53:01 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t bufer)
{
	size_t	i;
	size_t	n;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	n = ft_strlen(dst);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (bufer <= n)
		return (bufer + srclen);
	else
	{
		while (src[i] && n < bufer - 1)
		{
			dst[n] = src[i];
			n++;
			i++;
		}
		dst[n] = '\0';
	}
	return (dstlen + srclen);
}

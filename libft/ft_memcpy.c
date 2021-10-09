/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:52:21 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/01 19:52:22 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*str1;
	unsigned char		*str2;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (0);
	str1 = src;
	str2 = dst;
	i = 0;
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (str2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:52:35 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/01 19:52:36 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	a;

	if (n == (-2147483648))
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		a = n * (-1);
		write(fd, "-", 1);
		ft_putnbr_fd(a, fd);
	}
	else if (n <= 9)
	{
		a = n + 48;
		write(fd, &a, 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

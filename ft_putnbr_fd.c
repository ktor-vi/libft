/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:55:11 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/16 17:55:15 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	placeholder;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	placeholder = (char)(n % 10) + '0';
	write(fd, &placeholder, 1);
}

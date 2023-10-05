/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktorvi <ktorvi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:38:54 by ktorvi            #+#    #+#             */
/*   Updated: 2023/09/19 11:47:08 by ktorvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(char *__restrict str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_cstrlen(const char *__restrict str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *__restrict dst, const char *__restrict src,
		size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	i_dstlen;

	len = ft_cstrlen(src);
	j = 0;
	i = ft_strlen(dst);
	i_dstlen = ft_strlen(dst);
	if (dstsize <= i_dstlen)
		return (len + dstsize);
	while (src[j] != '\0' && j < dstsize - i_dstlen - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i_dstlen + len);
}

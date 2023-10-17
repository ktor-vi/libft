/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 07:27:20 by ktorvi            #+#    #+#             */
/*   Updated: 2023/10/16 14:10:13 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	sep_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_s_assign(char *src, char c)
{
	int		i;
	int		m_size;
	char	*s;

	i = 0;
	m_size = sep_len(src, c);
	s = malloc((m_size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (i < m_size)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static int	ft_wc(char *s, char c)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		if (s[j] != '\0')
			k++;
		while (s[j] != c && s[j] != '\0')
			j++;
	}
	return (k);
}

char	**ft_split(char *s, char c)
{
	char	**splitted;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	splitted = malloc((ft_wc(s, c) + 1) * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (s[j])
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		if (s[j] != '\0')
			splitted[k++] = ft_s_assign(s + j, c);
		while (s[j] != c && s[j] != '\0')
			j++;
	}
	splitted[k] = NULL;
	return (splitted);
}
// #include <stdio.h>
//
// int	main(int ac, char **av)
// {
// 	char	**table;
// 	int		i;
//
// 	(void)ac;
// 	i = 0;
// 	table = ft_split(av[1], av[2][0]);
// 	while (table[i])
// 	{
// 		printf("%s\n", table[i]);
// 		i++;
// 	}
// }

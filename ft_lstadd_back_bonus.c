/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:13:40 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/19 13:17:24 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	struct s_list	*last;

	if (new == NULL)
		return ;
	last = ft_lstlast(*lst);
	if (last != NULL)
	{
		last->next = new;
	}
	else
	{
		*lst = new;
	}
}

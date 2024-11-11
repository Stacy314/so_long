/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:50:36 by apechkov          #+#    #+#             */
/*   Updated: 2024/09/11 15:16:44 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*buff;
	void	*temp;

	buff = (void *)0;
	while (lst)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			ft_lstclear(&buff, del);
			return (free(temp), buff);
		}
		ft_lstadd_back(&buff, new);
		lst = lst->next;
	}
	return (buff);
}
// int main ()
// {
// 	ft_printf("\n");
// }
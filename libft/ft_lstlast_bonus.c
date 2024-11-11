/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:41:32 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/30 15:41:34 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int main()
{
    // Creating a linked list
    t_list *list = ft_lstnew("First");
    list->next = ft_lstnew("Second");
    list->next->next = ft_lstnew("Third");

    // Finding the last element of the list
    t_list *last = ft_lstlast(list);

    // Printing the last element (content)
    printf("Last element: %s\n", (char *)last->content);

    // Freeing the memory allocated for the list
    free(list->next->next->content);
    free(list->next->next);
    free(list->next->content);
    free(list->next);
    free(list);

    return 0;
}*/

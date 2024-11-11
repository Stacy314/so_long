/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:45:03 by apechkov          #+#    #+#             */
/*   Updated: 2024/09/22 22:39:12 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new1)
{
	t_list	*last;

	if (!new1)
		return ;
	if (!*lst)
	{
		*lst = new1;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new1;
}

/*int main()
{
    // Creating a linked list manually
    t_list *head = ft_lstnew("first");
    ft_lstadd_back(&head, ft_lstnew("second"));
    ft_lstadd_back(&head, ft_lstnew("third"));

    // Printing the content of the linked list
    printf("Content of the linked list:\n");
    t_list *current = head;
    while (current)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    // Freeing the memory allocated for the linked list
    current = head;
    while (current)
    {
        t_list *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}*/

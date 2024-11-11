/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:25 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/30 15:40:27 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*int main()
{
    // Creating a linked list with three elements
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->content = strdup("First");
    list->next = (t_list *)malloc(sizeof(t_list));
    list->next->content = strdup("Second");
    list->next->next = (t_list *)malloc(sizeof(t_list));
    list->next->next->content = strdup("Third");
    list->next->next->next = NULL;

    // Getting the size of the list
    int size = ft_lstsize(list);

    // Printing the size of the list
    printf("Size of the list: %d\n", size);

    // Freeing the memory allocated for the list
    while (list)
    {
        t_list *tmp = list->next;
        free(list->content);
        free(list);
        list = tmp;
    }

    return 0;
}*/

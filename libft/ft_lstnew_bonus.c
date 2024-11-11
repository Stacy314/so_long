/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:44:09 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 16:48:07 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)ft_calloc(sizeof(t_list) * 1, 1);
	if (new == 0)
		return ((t_list *)(void *)0);
	new->content = content;
	new->next = (t_list *)(void *)0;
	return (new);
}
/*int main()
{
    // Creating a new list node with content "Hello"
    t_list *new_node = ft_lstnew("Hello");

    // Printing the content of the new node
    printf("Content of the new node: %s\n", (char *)new_node->content);

    // Freeing the memory allocated for the new node
    free(new_node);

    return 0;
}*/
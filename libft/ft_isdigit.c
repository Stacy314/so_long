/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:50:25 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/05 16:54:17 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/*int main() {
    char test_char;
    printf("Enter a character: ");
    scanf("%c", &test_char);

    if (ft_isalnum(test_char))
        printf("%c is a digit.\n", test_char);
    else
        printf("%c is not a digit.\n", test_char);

    return 0;
}*/

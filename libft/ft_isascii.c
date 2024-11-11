/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:11:55 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/05 17:11:57 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*int main() {
    char test_char;
    printf("Enter a character: ");
    scanf("%c", &test_char);

    if (ft_isalnum(test_char))
        printf("%c is ascii.\n", test_char);
    else
        printf("%c is not ascii.\n", test_char);

    return 0;
}*/

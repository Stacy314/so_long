/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:16:48 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/05 17:18:58 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*int main() {
    char test_char;
    printf("Enter a character: ");
    scanf("%c", &test_char);

    if (ft_isalnum(test_char))
        printf("%c is printable ascii.\n", test_char);
    else
        printf("%c is not printable ascii.\n", test_char);

    return 0;
}*/

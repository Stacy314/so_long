/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:02:15 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/05 17:04:46 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}
/*int main() {
    char test_char;
    printf("Enter a character: ");
    scanf("%c", &test_char);

    if (ft_isalnum(test_char))
        printf("%c is an alphanumeric character.\n", test_char);
    else
        printf("%c is not an alphanumeric character.\n", test_char);

    return 0;
}*/

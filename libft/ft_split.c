/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:38:30 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 16:48:34 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (words);
}

static char	*symbol_count(char **s, char c)
{
	int		i;
	char	*symbols;
	char	*str;

	str = *s;
	i = 0;
	while (*str != '\0' && *str == c)
		str++;
	while (str[i] != '\0' && str[i] != c)
		i++;
	symbols = ft_calloc(sizeof(char) * (i + 1), 1);
	if (symbols == 0)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		symbols[i] = str[i];
		i++;
	}
	symbols[i] = '\0';
	*s = str + i;
	return (symbols);
}

static void	free_words(int i, char **ptr)
{
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_words;
	int		words;
	int		i;

	if (s == 0)
		return (0);
	words = word_count((char *)s, c);
	ptr_words = (char **)ft_calloc(sizeof(char *) * (words + 1), 1);
	if (ptr_words == 0)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s != '\0' && *s == c)
			s++;
		ptr_words[i] = symbol_count((char **)&s, c);
		if (ptr_words[i] == 0)
		{
			free_words(i, ptr_words);
			return (0);
		}
		i++;
	}
	ptr_words[i] = 0;
	return (ptr_words);
}

/*int main()
{
    char const *s = "Hello!";
    char c = 'l';
    char **result = ft_split(s, c);
    if (result)
    {
        int i = 0;
        while (result[i])
        {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
    {
        printf("Error: Unable to split the string.\n");
    }

    return 0;
}*/

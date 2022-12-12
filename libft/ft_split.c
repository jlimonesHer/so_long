/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:26:03 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/03 13:13:24 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_count(char const *s, char c, int p, unsigned int j)
{
	int	words;
	int	i;

	if (p == 0)
	{
		i = -1;
		words = 0;
		while (s[++i])
		{
			if (s[i] != c && j == 1)
				words++;
			if (s[i] != c)
				j = 0;
			else if (s[i] == c)
				j = 1;
		}
		return (words);
	}
	else
	{
		if (s[j] == c)
			return (1);
		return (0);
	}
}

static char	**ft_freewords(int words, char **tab)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_filltab(char const *s, char c, char **tab, int word)
{
	unsigned int	start;
	unsigned int	end;

	end = 0;
	while (ft_check_count(s, c, 1, end) == 1 && s[end])
		end++;
	while (s[end])
	{
		start = end;
		while (ft_check_count(s, c, 1, end) == 0 && s[end])
			end++;
		tab[word] = ft_substr(s, start, end - start);
		while (ft_check_count(s, c, 1, end) == 1 && s[end])
			end++;
		if (tab[word] == NULL)
			return (ft_freewords(word, tab));
		word++;
	}
	tab[word] = NULL;
	return (tab);
}

/**
 * 
 * @param s string que entra por parametro. 
 * @param c cararcter que encontrar para separar el string
 * @return char** matriz
 */

char	**ft_split(char const *s, char c)
{
	char			**tab;

	tab = malloc((ft_check_count(s, c, 0, 1) + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	if (!tab)
		return (NULL);
	tab = ft_filltab(s, c, tab, 0);
	return (tab);
}

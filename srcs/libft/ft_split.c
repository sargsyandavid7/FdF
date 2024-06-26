/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:39:58 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 17:42:50 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static size_t	count_size(char const *s, char c)
{
	size_t	size;
	size_t	i;
	int		flag;

	size = 0;
	i = 0;
	flag = 0;
	while (i <= ft_strlen(s))
	{
		flag = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			if (!flag)
			{
				flag = 1;
				size++;
			}
			i++;
		}
		i++;
	}
	return (size);
}

static	void	free_splited(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static void	fill_splited(char **splitted, char const *s, char c)
{
	size_t	i;
	size_t	lenght;
	size_t	sp_c;

	i = 0;
	lenght = 0;
	sp_c = 0;
	while (i <= ft_strlen(s))
	{
		lenght = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			lenght++;
		}
		if (lenght > 0)
			splitted[sp_c++] = ft_substr((char *)s, i - lenght, lenght);
		if (!splitted)
			free_splited(splitted);
		i++;
	}
}

char	**ft_split(char const *s, char c, int flag)
{
	size_t	size;
	char	**splitted;

	if (!s)
		return (NULL);
	size = count_size(s, c);
	if (!*s)
	{
		splitted = (char **)malloc(sizeof(char *) * (1));
		splitted[0] = NULL;
		return (splitted);
	}
	splitted = (char **)malloc(sizeof(char *) * (size + 1));
	if (!splitted)
	{
		free(splitted);
		return (NULL);
	}
	fill_splited(splitted, s, c);
	splitted[size] = NULL;
	if (!splitted)
		return (NULL);
	if (flag)
		free((char *)s);
	return (splitted);
}

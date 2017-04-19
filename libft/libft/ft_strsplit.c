/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:31:49 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/08 18:58:24 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char		*ft_gen(char *s, char c, size_t i)
{
	int		len;
	size_t	j;
	char	*new;
	char	*anchor;

	len = 0;
	j = i;
	while (s[j] != '\0' && s[j] != c)
	{
		len++;
		j++;
	}
	if ((new = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	anchor = new;
	while (len > 0)
	{
		*new++ = s[i++];
		len--;
	}
	*new = '\0';
	return (anchor);
}

static size_t	ft_scan_s(char *s, char c)
{
	int		is_word;
	size_t	length;

	is_word = 0;
	length = 0;
	while (*s != '\0')
	{
		if (*s == c && is_word == 1)
			is_word = 0;
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			length++;
		}
		s++;
	}
	return (length);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	len;
	char	**new_tab;
	char	**anchor;

	i = 0;
	len = ft_scan_s((char*)s, c);
	if ((new_tab = (char**)malloc((len + 1) * sizeof(char*))) == NULL)
		return (NULL);
	anchor = new_tab;
	while (len > 0)
	{
		while (s[i] == c && s[i])
			i++;
		*new_tab = ft_gen((char*)s, c, i);
		new_tab++;
		while (s[i] != c && s[i])
			i++;
		len--;
	}
	*new_tab = 0;
	return (anchor);
}

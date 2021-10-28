/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:30:38 by hbrent            #+#    #+#             */
/*   Updated: 2021/10/28 14:30:51 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] || s2[i])
	{
		if (i < n)
		{
			if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
				return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			k;
	char			*sub;
	unsigned int	strlen;

	k = 0;
	if (!s)
		return (NULL);
	strlen = (int)ft_strlen(s);
	if (start >= strlen)
	{
		sub = (char *)malloc(sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	if (start + len >= strlen)
		sub = (char *)malloc(sizeof(char) * (strlen - start));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (k < len && start < strlen)
		sub[k++] = s[start++];
	sub[k] = '\0';
	return (sub);
}

int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

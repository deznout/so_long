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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (0);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

static int	ft_nums(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] != c && s[i] != '\0') == 1)
			num++;
		i++;
	}
	return (num);
}

static char	**ft_clear(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static char	**ft_fill(char const *s, char c, char **res, int n)
{
	int	i;
	int	k;

	i = 0;
	while (i < n)
	{
		while (*s == c)
			s++;
		k = 0;
		while (s[k] && s[k] != c)
			k++;
		res[i] = (char *)malloc(sizeof(char) * k + 1);
		if (!res[i])
			return (ft_clear(res, i));
		ft_strlcpy(res[i], s, k + 1);
		s = s + k;
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (0);
	i = ft_nums(s, c);
	res = (char **)malloc(sizeof(char *) * i + 1);
	if (!res)
		return (NULL);
	res[i] = NULL;
	return (ft_fill(s, c, res, i));
}

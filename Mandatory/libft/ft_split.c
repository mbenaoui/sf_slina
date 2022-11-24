/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:49:21 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/23 22:22:05 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	num(char const *str, char c)
{
	int	i;
	int	j;
	int	k;
	int	ret;

	i = 0;
	j = 0;
	k = 0;
	ret = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			k++;
		}
		if (k != 0)
		{
			ret++;
			k = 0;
		}
	}
	return (ret);
}

static	int	hsapp(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static	char	**freemem(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**p;
	unsigned int	i;
	size_t			len;
	int				k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	p = (char **)malloc((sizeof(char *) * (num(s, c) + 1)));
	if (!p)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = hsapp(&s[i], c);
		if (len != 0)
			p[k++] = ft_substr(s, i, len);
		if (len != 0 && !p[k - 1])
			return (freemem(p));
		i = i + len;
	}
	p[k] = 0;
	return (p);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:39:05 by shan              #+#    #+#             */
/*   Updated: 2022/07/23 12:39:05 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		i++;
	}
	if (dstsize == 0)
		return (i);
	while (j < dstsize - 1 && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i1;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	i1 = 0;
	while (src[i1] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i1];
		i++;
		i1++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i1]));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		b;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	b = ft_strlen(s1);
	c = ft_strlen(s2);
	a = (char *)malloc((b + c + 1) * sizeof(char));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, b + 1);
	ft_strlcat(&a[ft_strlen(a)], s2, c + 1);
	return (a);
}

int	is_double(char **t)
{
	int	i;
	int	j;

	i = 0;
	while (t[i])
	{
		j = i + 1;
		while (t[j])
		{
			if (ft_atoi(t[i]) == ft_atoi(t[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

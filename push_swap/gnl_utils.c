/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 03:00:54 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 03:00:54 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointerdest;
	unsigned char	*pointersource;

	pointerdest = dest;
	pointersource = (unsigned char *)src;
	if (pointerdest == 0 && pointersource == 0)
		return (dest);
	while (n-- > 0)
		*pointerdest++ = *pointersource++;
	return (dest);
}

char	*ft_strjoin_g(char *s1, char const *s2)
{
	char			*pointer;
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	pointer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (pointer == 0)
		return (0);
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		pointer[i] = s2[j];
		i++;
		j++;
	}
	pointer[i] = '\0';
	ft_strdel(&s1);
	return (pointer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (s == 0)
		return (0);
	sub = malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	i = 0;
	while ((i < len) && (start < ft_strlen(s)))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

int	init_error(char *buffer)
{
	ft_strdel(&buffer);
	return (ERROR);
}

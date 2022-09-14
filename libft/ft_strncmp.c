/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:20:00 by shan              #+#    #+#             */
/*   Updated: 2022/01/07 04:06:25 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (c1[i] != '\0' && i < n)
	{
		if (c1[i] != c2[i])
		{
			if (c1[i] > c2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	if (c1[i] == '\0' && i < n)
		return (c1[i] - c2[i]);
	return (0);
}

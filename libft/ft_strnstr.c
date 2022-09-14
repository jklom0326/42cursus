/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:56:16 by shan              #+#    #+#             */
/*   Updated: 2021/12/21 02:29:26 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;

	needlelen = ft_strlen(needle);
	if (*needle)
	{
		if (len == 0)
			return (NULL);
		while (len-- && ft_strncmp(haystack, needle, needlelen) != 0)
		{
			if (len < needlelen)
				return (NULL);
			if (*haystack == '\0')
				return (NULL);
			haystack++;
		}
	}
	return ((char *)haystack);
}

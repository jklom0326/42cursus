/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:34:34 by shan              #+#    #+#             */
/*   Updated: 2022/01/10 21:47:10 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_wordcnt(const char *str, char c)
{
	size_t	cnt;
	size_t	check;

	cnt = 0;
	check = 0;
	while (*str != '\0')
	{
		if (*str != c && check == 0)
		{
			check = 1;
			cnt++;
		}
		else if (*str == c)
			check = 0;
		str++;
	}
	return (cnt);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strndup(const char *s, size_t num)
{
	char	*word;
	char	*temp;

	word = (char *)malloc(sizeof(char) * (num + 1));
	if (word == NULL)
		return (0);
	temp = word;
	while (num-- > 0)
		*temp++ = *s++;
	*temp = '\0';
	return (word);
}

static char	**ft_free(char ***s, int i)
{
	while (i--)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	*s = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb;
	size_t	wordlen;
	size_t	cnt;
	char	**result;

	if (s == NULL)
		return (0);
	cnt = ft_wordcnt(s, c);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (result == NULL)
		return (0);
	nb = 0;
	while (nb < cnt)
	{
		while (*s != '\0' && *s == c)
			s++;
		wordlen = ft_wordlen(s, c);
		result[nb] = ft_strndup(s, wordlen);
		if (result[nb] == NULL)
			return (ft_free(&result, wordlen - 1));
		s += wordlen;
		nb++;
	}
	result[cnt] = NULL;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:48:59 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 02:48:59 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

static char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s) + 1;
	dup = malloc(len * sizeof(char));
	if (dup)
		ft_memcpy(dup, s, len);
	return (dup);
}

static char	*ft_strchr(const char *str, int c)
{
	int		counter;
	int		len;
	char	*result;

	result = 0;
	counter = 0;
	len = ft_strlen(str) + 1;
	while (counter < len)
	{
		if (str[counter] == c)
		{
			result = (char *)str + counter;
			return (result);
		}
		counter++;
	}
	return (result);
}

static size_t	get_next_end(char *statico)
{
	size_t	i;

	i = 0;
	while (statico[i] != '\n' && statico[i] != '\0')
		i++;
	return (i);
}

static int	get_next_return(int n, char **statico, char **line)
{
	char	*temp;

	temp = NULL;
	*line = ft_substr(*statico, 0, get_next_end(*statico));
	if (line == 0 || n < 0)
	{
		ft_strdel(&*line);
		ft_strdel(statico);
		return (ERROR);
	}
	if (ft_strchr(*statico, '\n') != 0)
	{
		temp = ft_strdup(ft_strchr(*statico, '\n') + 1);
		ft_strdel(statico);
		*statico = temp;
		return (EOL);
	}
	ft_strdel(statico);
	return (FT_EOF);
}

int	get_next_line(int fd, char **line)
{
	static char		*statico;
	char			*buffer;
	int				nbytes;

	if (BUFFER_SIZE <= 0)
		return (ERROR);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == 0 || fd < 0 || line == 0)
		return (init_error(buffer));
	if (statico == 0)
		statico = ft_strdup("");
	while (1)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes <= 0)
			break ;
		buffer[nbytes] = '\0';
		statico = ft_strjoin_g(statico, buffer);
		if (ft_strchr(statico, '\n') != 0)
			break ;
	}
	ft_strdel(&buffer);
	return (get_next_return(nbytes, &statico, line));
}

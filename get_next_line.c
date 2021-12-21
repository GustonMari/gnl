/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:59:11 by gmary             #+#    #+#             */
/*   Updated: 2021/12/06 11:44:40 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_end(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(str) - i));
	i++;
	j = 0;
	while (str[i])
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	free(str);
	dest[j] = '\0';
	return (dest);
}

char	*ft_get_line(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*read_line(int fd, char *str)
{
	int		bytes;
	char	*buff;
	long	len_buffer;

	bytes = 1;
	len_buffer = BUFFER_SIZE;
	buff = malloc(sizeof(char) * (len_buffer + 1));
	if (!buff)
		return (NULL);
	while (bytes != 0 && ft_strchr(str, '\n') == 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && !*str))
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str = NULL;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_get_end(str);
	return (line);
}

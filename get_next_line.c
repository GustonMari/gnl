/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:59:11 by gmary             #+#    #+#             */
/*   Updated: 2021/12/03 15:48:54 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// a tej
#include <stdio.h>

char	*ft_get_end(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
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
	while (str[i] && str[i] != '\n')
		i++;
	/* bienfaire un malloc de deux pour chopper le \n issue du texte */
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	j = 0;
	/* <= et pas seulment < car on veut conserver le \n en fin de copy */
	while (j <= i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*read_line(int fd, char *buff, char *str)
{
	int	bytes;
	
	bytes = 1;
	while (bytes != 0 && ft_strchr(buff, '\n') == 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0 )
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	/* str est free dans chaque boucle dans strjoin */
	free(buff);
	return (str);
}

/* ne pas oublier buuffer neg ou 0 */

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*str = NULL;
	long		len_buffer;
	/* passer la taille du buffer en long pour ne pas avoir de probleme avec int max */

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (fd < 0 || fd > 1024 || !fd)
		return (NULL);
	len_buffer = BUFFER_SIZE;
	buff = malloc(sizeof(char) * (len_buffer + 1));
	if (!buff)
		return (NULL);
	/* strdup pour l'initialisation du strjoin */
	if (!str)
		str = ft_strdup("");
	str = read_line(fd, buff, str);
	/* ATTENTION ne surtout pas oublier de faire ce if car sinon on a pas de nul de fin */
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	/*ne surtout pas oublier de free str dans get end => permet de liberer dans get line et dans end */
	str = ft_get_end(str);
	return (line);
}

int	main()
{

	int	fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("bible.txt", O_RDONLY);
	//fd = open("text.txt", O_RDONLY);
	do
	{	
		str = get_next_line(fd);
		printf("ligne %d:%s", i, str);
		free(str);
		i++;
	}while (str);

	close(fd);
	return (0);
}

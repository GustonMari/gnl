/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:47:20 by gmary             #+#    #+#             */
/*   Updated: 2021/12/07 09:03:29 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_strlen( char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr( char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_get_end(char *str);
char	*ft_get_line(char *str);
char	*read_line(int fd, char *str);
char	*get_next_line(int fd);

#endif
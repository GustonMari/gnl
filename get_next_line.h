/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:47:20 by gmary             #+#    #+#             */
/*   Updated: 2021/12/03 11:33:32 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 4096
# endif
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>


int	ft_strlen( char *str);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strchr( char *s, int c);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strdup(const char *src);





#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:44:45 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/03 18:46:42 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000

# endif

char	*get_next_line(int fd);

char	*str_realloc(char *str, size_t size);

void	gnl_strcat(char *dst, const char *src, size_t size);
void	gnl_strcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif

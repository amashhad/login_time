/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_var.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:36:54 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/25 00:37:13 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_VAR_H
# define GET_NEXT_VAR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define FD_SIZE 1024
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

char	*ft_strchr_var(const char *s, int c);
char	*ft_substr_var(const char *s, unsigned int start, size_t len);
size_t	ft_strlen_var(const char *s);
char	*ft_strjoin_var(char *s1, char *s2);
size_t	ft_strlcpy_var(char *dst, const char *src, size_t size);
char	*ft_free_var(char **str);
char	*get_next_var(int fd, int var);
#endif

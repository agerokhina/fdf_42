/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:28 by aerokhin          #+#    #+#             */
/*   Updated: 2024/12/30 17:17:23 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*gnl(int fd);
ssize_t	ft_findchr(const char *s, int c);
ssize_t	ft_gnl_strlen(const char *str);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_substr(char const *s, unsigned int start, ssize_t len);
char	*my_read_fd(int fd, const char *str);
char	*ft_free(char **ptr);
char	*ft_free_all(char **ptr1, char **ptr2, int *ptr4);
char	*ft_start_checks(char **str, int *is_initialized, int fd);
char	*ft_copy_values(char **str, int i, int *is);

#endif
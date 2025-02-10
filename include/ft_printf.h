/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:56:37 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/11 15:51:57 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

char	*my_sub_c(int c, ssize_t *res_len);
char	*my_sub_p(uintptr_t address, ssize_t *res_len);
char	*my_sub_h_d(unsigned int nbr, char c, ssize_t *res_len);
ssize_t	my_address_len(uintptr_t nbr);
ssize_t	my_number_len(unsigned int nbr, int bas);
char	*my_case(char c, va_list args, ssize_t *substr_len);
char	*my_substring(const char *s, ssize_t	*subs_len);
char	*ft_memdup(const char *src, ssize_t len);
char	*ft_memjoin(char const *s1, ssize_t len1, char const *s2, ssize_t len2);
ssize_t	my_copysubstr(char **res, char c, va_list args, ssize_t *total_len);
ssize_t	my_combine(char **res, const char *s, ssize_t l, ssize_t *total_len);
char	*parse(const char *s, va_list args, ssize_t *total_len);
int		ft_printf(const char *s, ...);

#endif
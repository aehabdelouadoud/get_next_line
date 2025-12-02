/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:00:53 by abait-el          #+#    #+#             */
/*   Updated: 2025/12/02 06:13:55 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define YES 1
# define NO  0
# define MAX_FDS 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 555
# endif /* ifndef BUFFER_SIZE */

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_strjoin(char *s1, int free_s1, char *s2, int free_s2);
char	*gnl_strdup(const char *s);
char	*gnl_strcut(char **s, char sep);

#endif /* !GET_NEXT_LINE_BONUS_H */

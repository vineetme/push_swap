/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:51:08 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/03 17:47:36 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef NL
#  define NL 10
# endif

size_t		gnl_strlen(const char *str);
char		*get_next_line(int fd);
char		*extract_line(char *stash);
char		*clean_up(char *stash);
char		*gnl_strjoin(char *stash, char *buf);
char		*gnl_strchr(char *str, int c);

#endif

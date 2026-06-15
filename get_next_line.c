/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:12:44 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/03 18:03:07 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_up(stash);
	return (line);
}

static char	*read_and_stash(int fd, char *stash)
{
	ssize_t	bytes;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		stash = gnl_strjoin(stash, buf);
		if (!stash)
			break ;
		if (gnl_strchr(buf, NL))
			break ;
	}
	free(buf);
	if (bytes < 0)
		return (free(stash), NULL);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*ptr;	

	i = 0;
	if (!stash || !*stash)
		return (NULL);
	while (stash[i] != NL && stash[i] != '\0')
		i++;
	if (stash[i] == NL)
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (stash[i] != NL && stash[i] != '\0')
	{
		ptr[i] = stash[i];
		i++;
	}
	if (stash[i] == NL)
		ptr[i++] = NL;
	ptr[i] = '\0';
	return (ptr);
}

char	*clean_up(char *stash)
{
	int		i;
	int		j;
	char	*ptr;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != NL && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	ptr = malloc(gnl_strlen(stash + i + 1) + 1);
	if (!ptr)
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i] != '\0')
		ptr[j++] = stash[i++];
	ptr[j] = '\0';
	return (free(stash), ptr);
}

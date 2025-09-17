/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:31:49 by theo              #+#    #+#             */
/*   Updated: 2025/09/07 05:03:07 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*allocate_buff(size_t count, size_t size)
{
	unsigned char	*buff;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	buff = malloc(count * size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, count * size);
	return (buff);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
			i++;
	if (!stash[i])
		return (NULL);
	i++; // avance apres \n
	new_stash = allocate_buff(ft_strlen(stash + i) + 1, sizeof(char));
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i] != '\0')
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	//printf("%s", new_stash);
	return (new_stash);
}

char	*read_and_stash(int fd, char *s)
{
	int		read_bytes;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	if (!s)
		s = ft_strdup("");
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes == -1)
		return (NULL);
	while (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		tmp = s;
		s = ft_strjoin(s, buff);
		if (tmp)
			free(tmp);
		read_bytes = read(fd, buff, BUFFER_SIZE);
	}
	return (s);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (ft_strlen(stash) == 0)
			return (NULL);
	line = allocate_buff(ft_strlen(stash) + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++; // -> '\0'
	}
	line[i] = '\0'; // termine stash avec un '\0'
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0) // stdin -> (0)
		return (NULL);
//	if (!stash)
		stash = read_and_stash(fd, stash);
	line = extract_line(stash);
	if (!line)
			return (NULL);
	stash = clean_stash(stash);
	//printf("|%s|\n", stash);
	return (line);
}

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

int	main(void)
{
	int	fd;
	char	*s;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	s = get_next_line(fd);
	while (s != NULL) // récupère une ligne à chaque fois
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (0);
}

//read == 0 / EOF
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

char	*read_and_stash(int fd, char *stash)
{
	int		read_bytes;
	char	buff[BUFFER_SIZE];
	char	*tmp;

	if (!stash)
		return (ft_strdup(""));
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes == -1)
		return (NULL);
	while (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buff);
		if (tmp)
			free(tmp);
		read_bytes = read(fd, buff, BUFFER_SIZE); //	printf("%s", buff);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;
	
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

}

int	main(int ac, char **av)
{
	
	int	fd;
	char	*s; 

	s = NULL;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	get_next_line(fd);
	close(fd);
	return (0);
}


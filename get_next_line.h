/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:35:43 by theo              #+#    #+#             */
/*   Updated: 2025/09/06 20:14:41 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

/*fopen*/
# include <fcntl.h>

#define BUFFER_SIZE 42

/*get_next_reader*/
char	*get_next_line(int fd);

/*get_next_line.c*/
void	*allocate_buff(size_t count, size_t size);
char	*read_and_stash(int fd, char *stash);

/*get_next_line_utils.c*/
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char const *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *s1, char const *s2);
char	*ft_strdup(char *s1);

//int	main(void);

#endif

/*funct : read, malloc*/

/*Read line: correct behavior
NULL: there is nothing else to read, or an error
occurred*/

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c


/*Tu read BUFFER SIZE octet , que tu stock dans in buffer à chaque lecture tu concatene dans stash ta concatenation t’envoie un nouveau stash a chaque fois et le stash avant la concaténation tu le free , ensuite
C un strjoin un peu modifier*/

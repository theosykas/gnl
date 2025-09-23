/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:35:43 by theo              #+#    #+#             */
/*   Updated: 2025/09/23 19:26:48 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>

/*fopen*/
# include <fcntl.h>

//#define BUFFER_SIZE 42

/*get_next_line.c*/
void	*allocate_buff(size_t count, size_t size);
char	*read_and_stash(int fd, char *s);
char	*get_next_line(int fd);

/*get_next_line_utils.c*/
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
//char	*ft_strcpy(char *s1, char const *s2);
char	*ft_strdup(char *s1);

#endif

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

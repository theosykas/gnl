/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:31:27 by theo              #+#    #+#             */
/*   Updated: 2025/09/07 04:58:00 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	unsigned char *s_cast;

	if (n == 0)
		return ;
	i = 0;
	s_cast = s;
	while (n > i)
	{
		s_cast[i] = 0;
		i++;
	}
}

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	join = allocate_buff(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_strcpy(char *s1, char const *s2)
{
	int	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i;

	if (!s1)
		return (NULL);
	dup = allocate_buff(ft_strlen(s1) + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <string.h>

int	main(void)
{
	char	s1[20] = "theo";
	char	s2[] = "sks";

	printf("ft_strcat : %s\n", ft_strjoin(s1, s2));
	write (1, "\n", 1);

	char	s3[20] = "theo";
	printf("strcat : %s", strcat(s3, s2));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:53:11 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/11 12:56:36 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

static char	*ft_strdup(const char *s1)
{
	int		count;
	int		index;
	char	*dst;

	count = 0;
	while (s1[count] != '\0')
		count++;
	dst = (char *)malloc(sizeof(char) * (count + 1));
	if (dst == NULL)
		return (NULL);
	index = 0;
	while (index < count)
	{
		dst[index] = s1[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static int	ft_refresh_buffer(char **buffer,  int fd)
{
	char	*newbuffer;
	size_t	index;
	int		read_length;

	if (*buffer == NULL || ft_strlen(*buffer) != 0)
	{
		newbuffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!newbuffer)
			return (NULL);
		read_length = read(fd, buffer, BUFFER_SIZE);
		newbuffer[BUFFER_SIZE] = '\0';
		if (*buffer != NULL)
			free (*buffer);
		*buffer = newbuffer;
		return (read_length);
	}
	return (ft_strlen(*buffer));
}

static char	*ft_strjoin(char *str1, char *str2)
{
	int		index1;
	int		index2;
	char	*new_string;

	new_string = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_string)
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (str1[index1] != '\0')
	{
		new_string[index1] = str1[index1];
		index1++;
	}
	while (str2[index2] != '\0')
	{
		new_string[index1 + index2] = str2[index2];
		index2++;
	}
	new_string[index1 + index2] = '\0';
	free(str1);
	free(str2);
	return (new_string);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	int			index1;
	int			index2;
	char		*part_line;
	char		*full_line;
	int			buffer_length;

	buffer_length = ft_refresh_buffer(&buffer, fd);
	index1 = 0;
	full_line = NULL;
	while (buffer[index1] != '\n' && buffer[index1] != '\0')
		index1++;
	part_line = malloc(sizeof(char) * (index1 + 1));
	index2 = 0;
	while (index2 < index1)
	{
		part_line[index2] = buffer[index2];
		index2++;
	}
	part_line[index2] = '\0';
	full_line = ft_strjoin(full_line, part_line)

		return (full_line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	close(fd);
}
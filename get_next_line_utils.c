/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:31:59 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/11 17:55:04 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
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

int	ft_refresh_buffer(char **buffer, int fd)
{
	char	*newbuffer;
	int		read_size;

	if (*buffer == NULL || ft_strlen(*buffer) == 0)
	{
		read_size = read(fd, newbuffer, BUFFER_SIZE);
		// if (read_size <= 0)
		// 	return (-1);
		newbuffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!newbuffer)
			return (0);
		newbuffer[read_size] = '\0';
		if (*buffer != NULL)
			free (*buffer);
		*buffer = newbuffer;
		// if (read_size == 0)
		// 	return (0);
	}
	return (1);
}

void	ft_trim_buffer(char **buffer, size_t length)
{
	char	*newbuffer;
	size_t	index;
	size_t	original_length;

	original_length = ft_strlen(*buffer);
	if (original_length == length)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	newbuffer = (char *)malloc(sizeof(char) * (original_length - length + 1));
	if (!newbuffer)
		return ;
	index = 0;
	while (index < original_length - length)
	{
		newbuffer[index] = (*buffer)[length + index];
		index++;
	}
	newbuffer[index] = '\0';
	free(*buffer);
	*buffer = newbuffer;
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		index1;
	int		index2;
	char	*new_string;

	if (str1 == NULL)
		return (str2);
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
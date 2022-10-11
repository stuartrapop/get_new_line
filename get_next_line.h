/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:47:22 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/11 17:36:00 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
static const int	BUFFER_SIZE = 30;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *str);
int		ft_refresh_buffer(char **buffer, int fd);
void	ft_trim_buffer(char **buffer, size_t length);
char	*ft_strjoin(char *str1, char *str2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:00:44 by spaipur-          #+#    #+#             */
/*   Updated: 2025/08/11 09:51:42 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char *ft_join_n_free(char *buffer, char *new_buf)
{
	char *temp;
	
	temp = ft_strjoin(buffer, new_buf);
	free(buffer);
	return (temp);	
}

char *read_file(int fd, char *buffer)
{
	char *temp_buf;
	int bytes_read;
	
	temp_buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_buf)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if(bytes_read == 0) //&& ft_strlen(buffer) > 0)
			break;
		else if (bytes_read < 0)
		{
			if(buffer)
				free(buffer);
			free(temp_buf);
			return (NULL);
		}
		temp_buf[bytes_read] = '\0';
		buffer = ft_join_n_free(buffer, temp_buf);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(temp_buf);
	return (buffer);
}

char *ft_save_line(char *buffer)
{
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n') 
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while(buffer[i])
	{
		line[j++] = buffer[i];
		i++;
	}
	line[j] = '\0';
	free(buffer);
	return (line);
}

char *ft_next_line(char *buffer)
{
	char *line;
	int i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	next_line = ft_next_line(buffer[fd]);
	buffer[fd] = ft_save_line(buffer[fd]);
	return (next_line);
}

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	char *l;  

	fd = open("sample.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open file");
		return (1);
	}
	while ((l = get_next_line(fd)))
	{
		printf("%s", l);
		fflush(stdout);
		free(l);
	}
	close(fd);
	return (0);
}

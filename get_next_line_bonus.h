/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:16:41 by spaipur-          #+#    #+#             */
/*   Updated: 2025/08/11 09:51:50 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFERSIZE
# define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *ft_next_line(char *buffer);
char *ft_strjoin(char *s1,const char *s2);

#endif
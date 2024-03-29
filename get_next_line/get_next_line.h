/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:56:28 by gcools            #+#    #+#             */
/*   Updated: 2023/12/14 11:25:17 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *charset);
char	*ft_strjoin(char *s1, char *s2);
int		ft_count(char *charset);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, int c);
void	*ft_free(void *ptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:36:43 by phudyka           #+#    #+#             */
/*   Updated: 2022/06/10 18:13:16 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
int		ft_slasher(const char *str, int c);
char	*ft_wedding(char *s1, char *s2);
char	*ft_cut(char *temp);
char	*ft_recut(char *temp);
char	*ft_read(int fd, char *temp);
char	*get_next_line(int fd);

#endif

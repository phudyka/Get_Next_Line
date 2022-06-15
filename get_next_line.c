/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:07:28 by phudyka           #+#    #+#             */
/*   Updated: 2022/06/15 14:27:02 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut(char *temp)
{
	size_t	i;
	size_t	j;
	char	*cutted;

	if (!*temp)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	cutted = (char *)malloc(sizeof(char) * (i + 2));
	if (!cutted)
		return (NULL);
	j = 0;
	while (temp[j] && j <= i)
	{
		cutted[j] = temp[j];
		j++;
	}
	cutted[j] = '\0';
	return (cutted);
}

char	*ft_recut(char	*temp)
{
	size_t	i;
	size_t	j;
	char	*recutted;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free (temp);
		return (NULL);
	}
	recutted = (char *)malloc(sizeof(char) * (ft_strlen(temp) -i + 1));
	if (!recutted)
		return (NULL);
	j = 0;
	while (temp[i++])
		recutted[j++] = (temp[i]);
	recutted[j] = '\0';
	free(temp);
	return (recutted);
}

char	*ft_read(int fd, char *temp)
{
	int		byte;
	char	mini[BUFFER_SIZE + 1];

	byte = 1;
	while (!ft_slasher(temp, '\n') && byte)
	{
		byte = read(fd, mini, BUFFER_SIZE);
		if (byte == -1)
		{
			free (mini);
			return (NULL);
		}
		mini[byte] = '\0';
		temp = ft_wedding(temp, mini);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*maxi;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &maxi, 0) < 0)
		return (NULL);
	maxi = ft_read(fd, maxi);
	if (!maxi)
		return (NULL);
	line = ft_cut(maxi);
	maxi = ft_recut(maxi);
	return (line);
}

/*int	main(void)
{
	char	*str;
	int fd = open("123.txt", O_RDONLY);

	int i = 11;	
	while (i--){
	str = get_next_line(fd);
	if (!str)
		break;
	printf("STR :%s", str);
	free (str);
	}
	 system ("leaks a.out");
}*/

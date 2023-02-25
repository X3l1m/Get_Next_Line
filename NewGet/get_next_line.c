/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 23:08:09 by seyildir      #+#    #+#                 */
/*   Updated: 2023/02/25 23:21:36 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
		{
			if (str[i])
				return (i);
			return (-i);
		}
	}
	return (0);
}

char	*read_line(int fd, char *mem)
{
	ssize_t	readed;
	char	buffer[BUFFER_SIZE + 1];

	readed = read(fd, buffer, BUFFER_SIZE);
	if (!readed)
		return (mem);
	if (readed < 0)
		return (free(mem), NULL);
	buffer[readed] = 0;
	mem = ft_strjoin(mem, buffer);
	if (!mem)
		return (NULL);
	if (check_line(buffer))
		return (mem);
	return (read_line(fd, mem));
}

char	*find_next(char **mem)
{
	char	*line;
	int		i;

	i = check_line(*mem);
	if (i <= 0)
	{
		line = ft_strdup(*mem);
		free(*mem);
		*mem = NULL;
		return (line);
	}
	line = malloc((size_t)i + 1);
	if (!line)
		return (free(*mem), NULL);
	line[i] = 0;
	ft_memcpy(line, *mem, i);
	*mem = ft_strnew(*mem, i);
	if (!*mem)
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (NULL);
	if (!mem || !check_line(mem))
		mem = read_line(fd, mem);
	if (!mem)
		return (NULL);
	line = find_next(&mem);
	return (line);
}

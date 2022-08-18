/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:44:05 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 22:43:55 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char **backup);

int	check_line(char **str)
{
	int	i;

	i = -1;
	while ((*str)[++i])
	{
		if ((*str)[i] == '\n')
			return (1);
	}
	return (0);
}

char	*find_line(char	**str)
{
	char	*temp;
	char	*line;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	temp = (*str);
	line = ft_substr(temp, 0, (i + 1));
	if (!temp[i + 1])
		free_ptr(str, NULL);
	else
	{
		(*str) = ft_strdup(&temp[i + 1]);
		free(temp);
	}
	return (line);
}

char	*check_backup(char **backup, char **buffer)
{
	char	*line;

	if (!(*backup)[0])
		return (free_ptr(backup, buffer));
	line = ft_strdup(*backup);
	free_ptr(backup, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	if (!backup[fd])
	{
		backup[fd] = ft_strdup("");
		if (!backup[fd])
			return (NULL);
	}
	return (read_file(fd, &backup[fd]));
}

char	*read_file(int fd, char **backup)
{
	char	*buffer;
	char	*temp;
	int		n_let;

	while (1)
	{
		if (check_line(backup))
			return (find_line(backup));
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		n_let = read(fd, buffer, BUFFER_SIZE);
		if (n_let == -1)
			return (free_ptr(backup, &buffer));
		if (n_let == 0)
			return (check_backup(backup, &buffer));
		buffer[n_let] = '\0';
		temp = (*backup);
		*backup = ft_strjoin(*backup, buffer);
		free(temp);
		free(buffer);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 16:34:01 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 19:56:46 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static char			*ft_line(char *s)
{
	int				i;
	char			*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = ft_strnew(i);
	ft_strncpy(str, s, i);
	str[i] = '\0';
	return (str);
}

static char			*ft_stock(char *s)
{
	int				i;
	char			*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = ft_strdup(s + i + 1);
	ft_strdel(&s);
	return (str);
}

// static void				ft_norme(char **buff, char **line, char **save, int ret)
// {
// 	ft_strdel(buff);
// 	*line = ft_line(*save);
// 	if (ret == 0)
// 		ft_strdel(save);
// }

int					get_next_line_until(int const fd, char **line, int stop)
{
	int				ret;
	char			*temp;
	static char		*save;
	char			*buff;

	buff = ft_strnew(BUFF_SIZE + 1);
	save = (save == NULL) ? ft_strnew(1) : save;
	if (buff == NULL || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	ret = 42;
	while ((ft_strchr(save, '\n') == NULL) && ret > 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		temp = save;
		save = ft_strjoin(save, buff);
		ft_strdel(&temp);
	}
	ft_strdel(&buff);
	*line = ft_line(save);
	if (ret == 0 || stop == 1)
		ft_strdel(&save);
	if (ret == 0 && *line[0] == '\0')
		return (0);
	save = ft_stock(save);
	return (1);
}

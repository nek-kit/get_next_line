#include "get_next_line.h"

static int	ft_start(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_clean(char **end, int i)
{
	if (*end != 0 && i != 1)
	{
		free(*end);
		*end = NULL;
	}
	return (i);
}

static int	chg_end(char **end, char *buf)
{
	char	*str;

	str = 0;
	if (*end != 0)
		str = ft_strjoin(*end, buf);
	else
		str = ft_strdup(buf);
	if (str == 0)
		return (0);
	if (*end != 0)
		free(*end);
	*end = str;
	return (1);
}

static void	ft_scissor(char *end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (end == 0)
		return ;
	while (end[i] != '\n')
		i++;
	i++;
	while (end[i + j] != 0)
	{
		end[j] = end[i + j];
		j++;
	}
	end[j] = '\0';
}

int	get_next_line(int fd, char **line)
{
	static char	*end;
	char		buf[BUFFER_SIZE + 1];
	int			num;

	if (fd < 0)
		return (-1);
	num = 1;
	while (ft_start(end) == 0 && num != 0)
	{
		num = read(fd, buf, BUFFER_SIZE);
		if (num < 0 || BUFFER_SIZE < 1)
			return (ft_clean(&end, -1));
		buf[num] = '\0';
		if (chg_end(&end, buf) == 0)
			return (ft_clean(&end, -1));
	}
	*line = ft_strdupn(end);
	if (num == 0)
		return (ft_clean(&end, 0));
	ft_scissor(end);
	if (*line == 0)
		return (ft_clean(&end, -1));
	return (ft_clean(&end, 1));
}

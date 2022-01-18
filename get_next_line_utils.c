#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s12 = (char *)malloc(sizeof(char) * (i + j + 1));
	if (s12 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		s12[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		s12[i++] = s2[j++];
	s12[i] = '\0';
	return (s12);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;
	int		j;

	if (s1 == 0)
		return (NULL);
	j = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		copy[j] = s1[i];
		j++;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}

char	*ft_strdupn(const char *s1)
{
	char	*copy;
	int		i;
	int		j;

	if (s1 == 0)
		return (NULL);
	j = 0;
	while (s1[j] != 0 && s1[j] != '\n')
		j++;
	copy = (char *)malloc(sizeof(char) * (j + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		copy[j] = s1[i];
		j++;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}

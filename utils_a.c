#include "push_swap.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (str1 == str2)
		return (str1);
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (n == 0)
		return (str1);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while ((n--) && ((*s2 || *s1)))
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (str1);
}

char	*ft_strdup(const char *source)
{
	char	*res;

	res = malloc(ft_strlen(source) + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, source, ft_strlen(source) + 1);
	return (res);
}

static int	lenstr(char const *str, char c)
{
	int	i;
	int	size;
	int	len;

	i = 0;
	size = ft_strlen(str);
	len = 0;
	while (i < size)
	{
		while (i < size && str[i] == c)
			i++;
		if (str[i] == 0)
			break ;
		while (i < size && str[i] != c)
			i++;
		len++;
	}
	return (len);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i[2];
	int		index;
	char	**split;

	if (!s)
		return (0);
	split = malloc((lenstr(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	i[0] = 0;
	i[1] = 0;
	index = -1;
	while (i[0] <= ft_strlen(s))
	{
		if (s[i[0]] != c && index < 0)
			index = i[0];
		else if ((s[i[0]] == c || i[0] == ft_strlen(s)) && index >= 0)
		{
			split[i[1]++] = word_dup(s, index, i[0]);
			index = -1;
		}
		i[0]++;
	}
	split[i[1]] = 0;
	return (split);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
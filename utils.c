#include "push_swap.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	if (!dst && !size)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	if (size < i)
		i = size;
	j = 0;
	while ((j + i) < (size - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dst[i + j] = '\0';
	return (i + ft_strlen((char *)src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (lensrc);
	while (dstsize - 1 > i && lensrc > 0)
	{
		dst[i] = src[i];
		i++;
		lensrc--;
	}
	dst[i] = '\0';
	return (lensrc + i);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (--n > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_isdigit(int d)
{
	if (d >= 48 && d <= 57)
		return (1);
	return (0);
}

void	minmax(long int res, int sign)
{
	res = sign * res;
	if (res > 2147483647 || res < -2147483648)
		print_error();
}

int	ft_atoi(const char *str)
{
	long int	i[3];

	i[0] = 0;
	i[1] = 1;//res
	i[2] = 0;//sign
	while (str[i[0]] == ' ' || str[i[0]] == '\f' || str[i[0]] == '\t'
		|| str[i[0]] == '\v' || str[i[0]] == '\n' || str[i[0]] == '\r')
		i[0]++;
	if (str[i[0]] == '-')
		i[1] = -1;
	if((str[i[0]] == '+' || str[i[0]] == '-') && str[i[0]+1] == '\0')
		print_error();
	else if (str[i[0]] == '+' || str[i[0]] == '-')
		i[0]++;
	while (str[i[0]] != '\0')
	{
		if (ft_isdigit(str[i[0]]) == 0)
			print_error();
		i[2] = i[2] * 10 + str[i[0]] - '0';
		i[0]++;
	}
	minmax(i[2], i[1]);
	return (i[2]*i[1]);
}
#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	if (s)
// 	{
// 		while (s[i])
// 		{
// 			ft_putchar_fd(s[i], fd);
// 			i++;
// 		}
// 	}
// }

int	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
	else
		ft_putchar_fd('\0', fd);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (res);
}


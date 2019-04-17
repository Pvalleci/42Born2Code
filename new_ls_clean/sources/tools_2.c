
#include "ft_ls.h"

int		ft_is_not_directory(char *str)
{
	int				a;
	char			*s;
	struct stat		buf;

	s = ft_strdup(str);
	if (!s)
		return (-1);
	a = ft_strlen(s) - 1;
	while (s[a] == '/')
	{
		s[a] = '\0';
		a--;
	}
	if ((stat(s, &buf)) < 0)
	{
		ft_strdel(&s);
		return (1);
	}
	ft_strdel(&s);
	return (0);
}
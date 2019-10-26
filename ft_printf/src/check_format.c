
#include "ft_printf.h"

int		ft_general_check(char *f)
{
	int i;

	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			while (f[i] != 'd' && f[i] != 'i' && f[i] != 'o' && f[i] != 'u'
				&& f[i] != 'x' && f[i] != 'X' && f[i] != 'c' && f[i] != 's'
				&& f[i] != 'p' && f[i] != 'f' && f[i] != '%')
			{
				if ((f[i] != ' ' && f[i] != '+' && f[i] != '-' && f[i] != '#'
					&& f[i] != 'l' && f[i] != 'h' && f[i] != 'L'
					&& f[i] != '.' && f[i] != '9' && f[i] != '8'
					&& f[i] != '7' && f[i] != '6' && f[i] != '5'
					&& f[i] != '4' && f[i] != '3' && f[i] != '2'
					&& f[i] != '1' && f[i] != '0') || f[i] == '\0')
					return (-1);
				i++;
			}
		}
		i++;
	}
	return (i);
}

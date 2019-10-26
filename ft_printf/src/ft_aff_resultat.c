
#include "ft_printf.h"

static char		*ft_input_str(char *format, t_param *list, char *str)
{
	int i;
	int j;
	int l;

	i = 0;
	l = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (list->result[j])
			{
				str[l] = list->result[j];
				l++;
				j++;
			}
			i = i + ft_skip_param(format + i);
			list = list->next;
		}
		else
			str[l++] = format[i];
		i++;
	}
	return (str);
}

int				ft_affiche_resultat(char *format, t_param *list)
{
	int		len;
	int		i;
	char	*str;
	t_param	*start;

	len = 0;
	i = -1;
	start = list;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			len = len + ft_strlen(list->result);
			list = list->next;
			i = i + ft_skip_param(format + i);
			len--;
		}
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (0);
	ft_input_str(format, start, str);
	write(1, str, len);
	free(str);
	return (len);
}

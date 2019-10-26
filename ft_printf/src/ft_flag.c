
#include "ft_printf.h"

char	*ft_range_diu_flags(char *str, char *b, int range, t_param *list)
{
	int		i;
	int		j;

	j = 0;
	if (list->flag->minus == 1)
	{
		i = 0;
		if (str[i] == '-')
		{
			b[i++] = '-';
			j = i;
		}
		else if (list->flag->plus == 1)
			b[i++] = '+';
		while (str[j])
		{
			b[i] = str[j];
			i++;
			j++;
		}
	}
	else
		ft_diu_flag_no_minus(str, b, range, list);
	return (b);
}

char	*ft_range_diu_zero(char *str, char *b, int range, t_param *list)
{
	int i;

	i = 0;
	range--;
	if (str[0] == '-')
		b[i++] = '-';
	else if (list->flag->plus == 1)
		b[i++] = '+';
	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != '-')
	{
		b[range] = str[i];
		i--;
		range--;
	}
	return (b);
}

char	*ft_input_range_diu(char *str, char *b, int range, t_param *list)
{
	char	c;
	int		i;

	i = 0;
	c = ' ';
	if (list->flag->zero == 1)
		c = '0';
	while (i < range)
		b[i++] = c;
	if (c == '0')
		ft_range_diu_zero(str, b, range, list);
	else
		ft_range_diu_flags(str, b, range, list);
	return (b);
}

char	*ft_input_buf_diu(char *str, char *buffer, int len, t_param *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (list->flag->plus == 1 && str[0] != '-')
		buffer[i++] = '+';
	else if (list->flag->space == 1 && str[0] != '-')
		buffer[i++] = ' ';
	while (i < len)
	{
		buffer[i] = str[j];
		i++;
		j++;
	}
	return (buffer);
}

char	*ft_flag_diu(t_param *list, char *str)
{
	char	*buffer;
	int		len;

	len = ft_strlen(str);
	if ((list->flag->space == 1 && list->range <= len && str[0] != '-')
		|| (list->flag->plus == 1 && str[0] != '-'))
		len++;
	if (list->range > len)
	{
		if (!(buffer = ft_strnew(list->range)))
			return (NULL);
		ft_input_range_diu(str, buffer, list->range, list);
	}
	else
	{
		if (!(buffer = ft_strnew(len)))
			return (NULL);
		ft_input_buf_diu(str, buffer, len, list);
	}
	free(str);
	return (buffer);
}

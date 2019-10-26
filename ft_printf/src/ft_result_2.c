
#include "ft_printf.h"

char	*ft_get_result_s_range(char *str, t_param *list, int *i)
{
	if (!(list->result = ft_strnew(list->range)))
		return (NULL);
	if (list->flag->minus == 1)
	{
		(*i) = (int)ft_strlen(str);
		while ((*i) < list->range)
			list->result[(*i)++] = ' ';
		(*i) = 0;
	}
	else
	{
		while ((*i) < (list->range - (int)ft_strlen(str)))
			list->result[(*i)++] = ' ';
	}
	return (str);
}

char	*ft_get_result_s(t_param *list)
{
	char	*str;
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	str = (char *)list->variable;
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		tmp = str;
	}
	if (list->precision != -1 && (list->precision < (int)ft_strlen(str)))
		str = ft_precision(str, list);
	if ((int)ft_strlen(str) < list->range)
		ft_get_result_s_range(str, list, &i);
	else if (!(list->result = ft_strnew(ft_strlen(str))))
		return (NULL);
	ft_memmove(list->result + i, str, ft_strlen(str));
	if (tmp != NULL && list->precision == -1)
		free(tmp);
	return (list->result);
}

char	*ft_get_result_c(t_param *list)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (list->range > 1)
	{
		if (!(list->result = ft_strnew(list->range)))
			return (NULL);
		if (list->conversion == '%' && list->flag->zero == 1)
			c = '0';
		while (i < list->range)
			list->result[i++] = c;
		if (list->flag->minus == 1)
			i = 1;
		i--;
	}
	else if (!(list->result = ft_strnew(1)))
		return (NULL);
	if (list->variable == 0)
		list->result[i] = '\0';
	else
		list->result[i] = (char)list->variable;
	return (list->result);
}

char	*ft_get_result_di(t_param *list)
{
	char	*str;
	int		a;

	if (list->modifier == 1)
		str = ft_inttoa((int8_t)list->variable);
	else if (list->modifier == 2)
		str = ft_inttoa((int16_t)list->variable);
	else if (list->modifier == 0)
		str = ft_inttoa((int32_t)list->variable);
	else
		str = ft_inttoa((int64_t)list->variable);
	a = 0;
	if (str[0] == '-')
		a = 1;
	if ((list->precision > ((int)ft_strlen(str) - a))
		|| (list->precision == 0 && list->variable == 0))
		str = ft_precision(str, list);
	str = ft_flag_diu(list, str);
	return (str);
}

char	*ft_get_result_u(t_param *list)
{
	char	*str;

	if (list->modifier == 1)
		str = ft_utoa((uint8_t)list->variable);
	else if (list->modifier == 2)
		str = ft_utoa((uint16_t)list->variable);
	else if (list->modifier == 0)
		str = ft_utoa((uint32_t)list->variable);
	else
		str = ft_utoa((uint64_t)list->variable);
	if ((list->precision > (int)ft_strlen(str))
		|| (list->precision == 0 && list->variable == 0))
		str = ft_precision(str, list);
	list->flag->plus = 0;
	list->flag->space = 0;
	str = ft_flag_diu(list, str);
	return (str);
}

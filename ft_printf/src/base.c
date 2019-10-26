
#include "ft_printf.h"

char	*ft_copy_ptr(char *str, t_param *list, char *base, int a)
{
	uint64_t	val_base;
	uint64_t	var;
	int			i;

	i = ft_len_number(list->variable, (uint64_t)ft_strlen(base)) + a;
	if (i < list->range)
		i = list->range;
	if (list->flag->minus == 1)
		i = ft_len_number(list->variable, (uint64_t)ft_strlen(base)) + a;
	i--;
	val_base = (uint64_t)ft_strlen(base);
	var = list->variable;
	while (var > val_base - 1)
	{
		str[i] = base[var % val_base];
		var = var / val_base;
		i--;
	}
	str[i] = base[var % val_base];
	return (str);
}

char	*ft_pointeur(t_param *list)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_len_number(list->variable, 16) + 2;
	if (len < list->range)
	{
		if (!(str = ft_strnew(list->range)))
			return (NULL);
		while (i < list->range)
			str[i++] = ' ';
		if (list->flag->minus == 1)
			i = 0;
		else
			i = i - len;
	}
	else if (!(str = ft_strnew(len + 2)))
		return (NULL);
	str[i] = '0';
	str[i + 1] = 'x';
	ft_copy_ptr(str, list, "0123456789abcdef", 2);
	return (str);
}

char	*ft_copy_xxo(char *tmp, char *str, t_param *list, int a)
{
	int		i;
	int		j;

	j = (int)ft_strlen(str) - 1;
	if (list->flag->minus == 1)
		i = (int)ft_strlen(str) + a - 1;
	else
		i = ft_strlen(tmp) - 1;
	while (j >= 0)
	{
		tmp[i] = str[j];
		i--;
		j--;
	}
	if (a == 1)
		tmp[i] = '0';
	else if (a == 2)
	{
		if (list->flag->zero == 1)
			i = 1;
		tmp[i--] = list->conversion;
		tmp[i] = '0';
	}
	return (tmp);
}

char	*ft_range_xxo(char *str, t_param *list, int a, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if (list->flag->ash == 0 || (list->conversion == 'o' && str[0] == '0'))
		a = 0;
	if (list->range > ((int)ft_strlen(str) + a))
	{
		if (!(tmp = ft_strnew(list->range)))
			return (NULL);
		tmp = ft_bchar(tmp, list->range, c);
	}
	else if (a != 0)
	{
		if (!(tmp = ft_strnew(ft_strlen(str) + a)))
			return (NULL);
		tmp = ft_bchar(tmp, (int)ft_strlen(str) + a, c);
	}
	else
		return (str);
	tmp = ft_copy_xxo(tmp, str, list, a);
	free(str);
	return (tmp);
}

char	*ft_hexa(uint64_t variable, char *base, int len_base)
{
	char	*str;
	int		len;

	len = ft_len_number(variable, len_base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	len--;
	while (len > 0)
	{
		str[len] = base[variable % len_base];
		variable = variable / len_base;
		len--;
	}
	str[len] = base[variable % len_base];
	return (str);
}

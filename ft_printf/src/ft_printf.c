
#include "ft_printf.h"

static t_param		*ft_create_maillon(char *format)
{
	t_param		*maillon;
	int			len;

	len = ft_skip_param(format);
	if (!(maillon = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	maillon->conversion = format[len];
	maillon->modifier = ft_get_modifier(format, len);
	maillon->precision = ft_get_precision(format, len);
	maillon->range = ft_get_range(format, len);
	maillon->flag = ft_get_flag(format, len);
	maillon->next = NULL;
	if (maillon->precision != -1)
		maillon->flag->zero = 0;
	return (maillon);
}

static t_param		*ft_create_list(char *format)
{
	int			i;
	t_param		*list;
	t_param		*depart;

	i = 0;
	depart = NULL;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (depart == NULL)
				depart = ft_create_maillon(format + i);
			else
			{
				list = depart;
				while (list->next != NULL)
					list = list->next;
				list->next = ft_create_maillon(format + i);
			}
			i = i + ft_skip_param(format + i);
		}
		i++;
	}
	return (depart);
}

t_param				*ft_input_variable(t_param *list, va_list ap)
{
	t_param	*start;

	start = list;
	while (list != NULL)
	{
		if (list->conversion == 'c' || list->conversion == 's'
		|| list->conversion == 'p' || list->conversion == '%')
			list->variable = ft_get_var_csp(list, ap);
		else if (list->conversion == 'd' || list->conversion == 'i')
			list->variable = ft_get_var_di(list, ap);
		else if (list->conversion == 'u' || list->conversion == 'x'
			|| list->conversion == 'X' || list->conversion == 'o')
			list->variable = ft_get_var_uoxx(list, ap);
		else if (list->conversion == 'f')
			list->variable = ft_get_var_float(list, ap);
		list = list->next;
	}
	return (start);
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	t_param		*list;
	int			result;

	result = 0;
	if (ft_check_format((char *)format) == 1)
	{
		if (ft_general_check((char *)format) == -1)
			return (0);
		list = ft_create_list((char *)format);
		va_start(ap, format);
		list = ft_input_variable(list, ap);
		va_end(ap);
		list = ft_get_result(list);
		result = ft_affiche_resultat((char *)format, list);
		ft_free_list(list);
	}
	else
	{
		result = ft_strlen(format);
		write(1, format, result);
	}
	return (result);
}

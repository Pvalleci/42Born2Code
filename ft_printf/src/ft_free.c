
#include "ft_printf.h"

void	ft_free_list(t_param *list)
{
	if (list->next != NULL)
		ft_free_list(list->next);
	free(list->result);
	free(list->flag);
	free(list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:28:14 by ythomas           #+#    #+#             */
/*   Updated: 2019/02/02 14:04:26 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_flag
{
	int				space;
	int				ash;
	int				zero;
	int				minus;
	int				plus;
}					t_flag;

typedef struct		s_param
{
	char			*result;
	uint64_t		variable;
	long double		varfloat;
	t_flag			*flag;
	int				range;
	int				precision;
	int				modifier;
	char			conversion;
	struct s_param	*next;
}					t_param;

int					ft_printf(const char *format, ...);
int					ft_get_modifier(char *format, int len);
int					ft_get_precision(char *format, int len);
int					ft_get_range(char *format, int len);
t_flag				*ft_get_flag(char *format, int len);
uint64_t			ft_get_var_csp(t_param *list, va_list ap);
uint64_t			ft_get_var_di(t_param *list, va_list ap);
uint64_t			ft_get_var_uoxx(t_param *list, va_list ap);
uint64_t			ft_get_var_float(t_param *list, va_list ap);
t_param				*ft_get_result(t_param *list);
char				*ft_inttoa(int64_t n);
char				*ft_utoa(uint64_t nb);
char				*ft_flag_diu(t_param *list, char *str);
char				*ft_pointeur(t_param *list);
char				*ft_hexa(uint64_t variable, char *base, int len_base);
int					ft_affiche_resultat(char *format, t_param *list);
int					ft_skip_param(char *f);
char				*ft_get_result_s(t_param *list);
char				*ft_get_result_c(t_param *list);
char				*ft_get_result_di(t_param *list);
char				*ft_get_result_u(t_param *list);
int					ft_len_number(uint64_t nb, uint64_t val_base);
char				*ft_diu_flag_no_minus(char *str, char *b,
					int range, t_param *list);
t_flag				*ft_inti_struct_flag(t_flag *flag);
t_flag				*ft_exception_flag(t_flag *flag);
int					ft_check_format(char *format);
int					ft_skip_param(char *f);
char				*ft_precision(char *str, t_param *list);
char				*ft_range_xxo(char *str, t_param *list, int a, char c);
char				*ft_bchar(char *tmp, int len, char c);
void				ft_free_list(t_param *list);
char				*ft_float(long double varfloat, t_param *list);
int					ft_general_check(char *f);

#endif
